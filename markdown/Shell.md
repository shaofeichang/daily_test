# shell 基础  

1. 作为可执行程序

```shell
#!/bin/bash
echo "Hello World !"
```
**#!** 是一个约定的标记，它告诉系统这个脚本需要什么解释器来执行，即使用哪一种 Shell。
echo 命令用于向窗口输出文本。
将编辑好的的代码保存为`test.sh`，并 cd 到相应目录：
`chmod +x ./test.sh`  使脚本具有执行权限
`./test.sh`  #执行脚本
注意，一定要写成 **`./test.sh`**，而不是 **`test.sh`**，运行其它二进制的程序也一样，直接写 `test.sh`，linux 系统会去 PATH 里寻找有没有叫`test.sh` 的，而只有 /bin, /sbin, /usr/bin，/usr/sbin 等在 PATH 里，你的当前目录通常不在 PATH 里，所以写成`test.sh` 是会找不到命令的，要用 `./test.sh`  告诉系统说，就在当前目录找。

2. 作为解释器参数

这种运行方式是，直接运行解释器，其参数就是 shell 脚本的文件名，如：

```shell
/bin/sh test.sh
/bin/php test.php
```
这种方式运行的脚本，不需要在第一行指定解释器信息，写了也没用。

##　shell 字符串

1. **#、##**表示从左边开始删除，一个 **#** 表示从左边删除到第一个指定的字符；两个 **##** 表示从左边删除到最后一个指定的字符。
2. **%、%%**表示从右边开始删除，一个 **%** 表示从右边删除到第一个指定的字符，**%%**表示从右边删除到最后一个指定的字符。
删除包括了指定的字符本身。

假设有变量`var=http://www.aaa.com/123.html`
1. #截取，删除左边的字符，保留右边的字符
`echo ${var#*//}`
var:变量名
\#：运算符
*//：表示从左边开始删除第一个//号及左边的所有字符
结果：www.aaa.com/123.html
2. ##截取，删除左边的字符，保留右边的字符
`echo ${var##*/}`
\##*/:表示从左边开始删除最后一个/号及左边的所有字符
结果：123.html
3. %截取，删除右边字符，保留左边字符
`echo ${var%/*}`
%/*:表示从右边开始，删除第一个/号及右边的字符
结果:http://www.aaa.com
4. %%截取，删除右边字符，保留左边字符
`echo ${var%%/*}`
%%/*:表示从右边开始，删除最后（左边）一个/号及右边的字符
结果：http:
5. 从左边第几个字符开始，及字符的个数
`echo ${var:7}`
结果：http:
6. 从左边第几个字符开始，一直到结束。
`echo ${var:7}`
其中的 7 表示左边第8个字符开始，一直到结束。
结果是 ：www.aaa.com/123.htm
7. 从右边第几个字符开始，及字符的个数
`echo ${var:0-7:3}`
其中的 0-7 表示右边算起第七个字符开始，3 表示字符的个数。
结果是：123
8. 从右边第几个字符开始，一直到结束。
`echo ${var:0-7}`
表示从右边第七个字符开始，一直到结束。
结果是：123.htm

