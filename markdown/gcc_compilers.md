# GCC编译器
Gcc的编译流程分为四个步骤：
- 1. 预处理，生成预编译文件(.i文件)：```gcc -E hello.c -o hello.i```
- 2. 编译，生成汇编代码（.s文件）：```gcc -S hello.i -o hello.s```
- 3. 汇编，生成目标文件（.o文件）：```gcc -c hello.s -o hello.o```
- 4. 链接，生成可执行文件：```gcc hello.o -o hello```