# Linux动态库笔记
Linux下动态库文件的文件名形如 ```libxxx.so```，其中so是 Shared Object 的缩写，即可以共享的目标文件。

在链接动态库生成可执行文件时，并不会把动态库的代码复制到执行文件中，而是在执行文件中记录对动态库的引用。

程序执行时，再去加载动态库文件。如果动态库已经加载，则不必重复加载，从而能节省内存空间。

Linux下生成和使用动态库的步骤如下：

1. 编写源文件。
2. 将一个或几个源文件编译链接，生成共享库。
3. 通过 ```-L<path> -lxxx``` 的gcc选项链接生成的```libxxx.so```。
4. 把```libxxx.so```放入链接库的标准路径，或指定 ```LD_LIBRARY_PATH```，才能运行链接了```libxxx.so```的程序。
下面通过实例详细讲解。

## demo1 直接使用动态库

编写测试代码

```c
// max.c
int max(int n1, int n2, int n3)
{
    int max_num = n1;
    max_num = max_num < n2? n2: max_num;
    max_num = max_num < n3? n3: max_num;
    return max_num;
}
```
```c
//max.h
#ifndef __MAX_H__
#define __MAX_H__
int max(int n1, int n2, int n3);
#endif
 ```

```c
//main.c
 #include <stdio.h>
 #include "max.h"
int main(int argc, char *argv[])
{
    int a = 10, b = -2, c = 100;
    printf("max among 10, -2 and 100 is %d.\n", max(a, b, c));
    return 0;
}
 ```
编译生成共享库：
```gcc -fPIC -shared -o libmax.so max.c```
我们会得到```libmax.so```。

实际上上述过程分为编译和链接两步， ```-fPIC```是编译选项，PIC是 Position Independent Code 的缩写，表示要生成位置无关的代码，这是动态库需要的特性； ```-shared```是链接选项，告诉gcc生成动态库而不是可执行文件。

上述的一行命令等同于：
```gcc -c -fPIC max.c```
```gcc -shared -o libmax.so max.o```
为动态库编写接口文件
为了让用户知道我们的动态库中有哪些接口可用，我们需要编写对应的头文件。

```gcc test.c -L. -lmax ```生成a.out，其中```-lmax```表示要链接```libmax.so```。
```-L.```表示搜索要链接的库文件时包含当前路径。

注意，如果同一目录下同时存在同名的动态库和静态库，比如 ```libmax.so``` 和 ```libmax.a``` 都在当前路径下，则gcc会优先链接动态库。
运行
运行 ```./a.out``` 会得到以下的错误提示。

```./a.out: error while loading shared libraries: libmax.so: cannot open shared object file: No such file or directory```
找不到```libmax.so```，原来Linux是通过 ```/etc/ld.so.cache ```文件搜寻要链接的动态库的。
而 ```/etc/ld.so.cache``` 是 ```ldconfig``` 程序读取 ```/etc/ld.so.conf``` 文件生成的。
（注意， ```/etc/ld.so.conf``` 中并不必包含 ``````/lib 和 ```/usr/lib```，```ldconfig```程序会自动搜索这两个目录）

如果我们把 ```libmax.so``` 所在的路径添加到 ```/etc/ld.so.conf``` 中，再以root权限运行 ldconfig 程序，更新 ```/etc/ld.so.cache``` ，a.out运行时，就可以找到 ```libmax.so```。

但作为一个简单的测试例子，让我们改动系统的东西，似乎不太合适。
```export LD_LIBRARY_PATH="./:$LD_LIBRARY_PATH"```
还有另一种简单的方法，就是为a.out指定 ```LD_LIBRARY_PATH```。
```LD_LIBRARY_PATH=. ./a.out```
程序就能正常运行了。```LD_LIBRARY_PATH=.``` 是告诉 a.out，先在当前路径寻找链接的动态库。

对于elf格式的可执行程序，是由```ld-linux.so*```来完成的，它先后搜索elf文件的 DT_RPATH 段, 环境变量 ```LD_LIBRARY_PATH```, ```/etc/ld.so.cache```文件列表, /lib/,/usr/lib目录, 找到库文件后将其载入内存. (http://blog.chinaunix.net/uid-23592843-id-223539.html)

makefile让工作自动化
编写makefile，内容如下：
```
.PHONY: build test clean

build: libmax.so

libmax.so: max.o
	gcc -o $@  -shared $<

max.o: max.c
	gcc -c -fPIC $<

test: a.out

a.out: test.c libmax.so
	gcc test.c -L. -lmax
	LD_LIBRARY_PATH=. ./a.out

clean:
	rm -f *.o *.so a.out
```
make build就会生成libmax.so， make test就会生成a.out并执行，make clean会清理编译和测试结果。

## demo2 函数加载动态库

Linux提供```dlopen、dlsym、dlerror和dlcolose```函数获取动态链接库的函数。
通过这个四个函数可以实现一个插件程序，方便程序的扩展和维护。函数格式如下所示：

```c
#include <dlfcn.h>

void *dlopen(const char *filename, int flag);

char *dlerror(void);

void *dlsym(void *handle, const char *symbol);

int dlclose(void *handle);
Link with -ldl.
 ```

dlopen()是一个强大的库函数。该函数将打开一个新库，并把它装入内存。该函数主要用来加载库中的符号，这些符号在编译的时候是不知道的。写个测试程序调用上面生产libcac.so库如下所示：

```c
 //caculate.h
 
 #ifndef CACULATE_HEAD_
 #define CACULATE_HEAD_
 //加法
 int add(int a, int b);
 //减法
 int sub(int a, int b);
 //除法
 int div(int a, int b);
 //乘法
 int mul(int a, int b);
 
 #endif
  ```

```c
// calculate.c
#include "caculate.h"
int add(int a, int b)
{
    return (a + b);
}
//减法
int sub(int a, int b)
{
    return (a - b);
}
//除法
int div(int a, int b)
{
    return (int)(a / b);
}
//乘法
int mul(int a, int b)
{
    return (a * b);
}
```

```c
// main.c
#include <stdio.h>
#include <dlfcn.h>

#define DLL_FILE_NAME "libcac.so"

int main()
{
    void *handle;
    int (*func)(int, int);
    char *error;
    int a = 30;
    int b = 5;

    handle = dlopen(DLL_FILE_NAME, RTLD_NOW);
    if (handle == NULL)
    {
    fprintf(stderr, "Failed to open libaray %s error:%s\n", DLL_FILE_NAME, dlerror());
    return -1;
    }

    func = dlsym(handle, "add");
    printf("%d + %d = %d\n", a, b, func(a, b));

    func = dlsym(handle, "sub");
    printf("%d + %d = %d\n", a, b, func(a, b));

    func = dlsym(handle, "div");
    printf("%d + %d = %d\n", a, b, func(a, b));
    
    func = dlsym(handle, "mul");
    printf("%d + %d = %d\n", a, b, func(a, b));

    dlclose(handle);
    return 0;
}
```
执行程序```gcc main.c -o main -ldl```
```-ldl```表示生成的对象模块需要用到共享库,主要是用到了``` dlopen ```等函数需要用到此选项