# Linux基本操作

## 文章目录

[一、系统监控]( ###一、系统监控)

1. free命令
2. ulimit命令
3. top命令
4. df命令
5. ps命令

[二、文件操作]( ###二、文件操作)

1. tail命令
2. ll -ah

[三、网络通信]( ###三、网络通信)

1. netstat
2. 重启网络
3. SELinux
4. 防火墙

[四、系统管理]( ###四、系统管理)

1. uname
2. ip addr

### 一、系统监控

1、free命令
free 命令能够显示系统中物理上的空闲和已用内存，还有交换内存，同时，也能显示被内核使用的缓冲和缓存
语法：`free [param]`
param可以为：
- -b：以Byte为单位显示内存使用情况；
- -k：以KB为单位显示内存使用情况；
- -m：以MB为单位显示内存使用情况；
- -o：不显示缓冲区调节列；
- -s<间隔秒数>：持续观察内存使用状况；
- -t：显示内存总和列；
- -V：显示版本信息。

- Mem：表示物理内存统计
- total：表示物理内存总数(total=used+free)
- used：表示系统分配给缓存使用的数量(这里的缓存包括buffer和cache)
- free：表示未分配的物理内存总数
- shared：表示共享内存
- buffers：系统分配但未被使用的buffers 数量。
- cached：系统分配但未被使用的cache 数量。
- -/+ buffers/cache：表示物理内存的缓存统计
- (-buffers/cache) 内存数： (指的第一部分Mem行中的used – buffers – cached)
- (+buffers/cache) 内存数: (指的第一部分Mem行中的free + buffers + cached)
- (-buffers/cache)表示真正使用的内存数， (+buffers/cache) 表示真正未使用的内存数
- Swap：表示硬盘上交换分区的使用情况

2、ulimit命令
ulimit用于显示系统资源限制的信息
语法：`ulimit [param]`
param参数可以为：
- -a 　显示目前资源限制的设定。
- -c <core文件上限> 　设定core文件的最大值，单位为区块。
- -d <数据节区大小> 　程序数据节区的最大值，单位为KB。
- -f <文件大小> 　shell所能建立的最大文件，单位为区块。
- -H 　设定资源的硬性限制，也就是管理员所设下的限制。
- -m <内存大小> 　指定可使用内存的上限，单位为KB。
- -n <文件数目> 　指定同一时间最多可开启的文件数。
- -p <缓冲区大小> 　指定管道缓冲区的大小，单位512字节。
- -s <堆叠大小> 　指定堆叠的上限，单位为KB。
- -S 设定资源的弹性限制。
- -t <CPU时间> 　指定CPU使用时间的上限，单位为秒。
- -u <程序数目> 　用户最多可开启的程序数目。
- -v <虚拟内存大小> 　指定可使用的虚拟内存上限，单位为KB
3、top命令
top命令可以实时动态地查看系统的整体运行情况，是一个综合了多方信息监测系统性能和运行信息的实用工具

语法：`top [param]`

param为：
- -b：以批处理模式操作；
- -c：显示完整的治命令；
- -d：屏幕刷新间隔时间；
- -I：忽略失效过程；
- -s：保密模式；
- -S：累积模式；
- -u [用户名]：指定用户名；
- -p [进程号]：指定进程；
- -n [次数]：循环显示的次数。
- 4、df命令
- df -h查看磁盘使用情况
- df -i 查看inode使用情况
5、ps命令
ps命令用于查看进程统计信息

常用参数：
- -a：显示当前终端下的所有进程信息，包括其他用户的进程。
- -u：使用以用户为主的格式输出进程信息。
- -x：显示当前用户在所有终端下的进程。
- -e：显示系统内的所有进程信息。
- -l：使用长（long）格式显示进程信息。
- -f：使用完整的（full）格式显示进程信息。
在使用中可以加上grep命令一起使用，也可以单独使用

**ps命令单独使用的情况**
`ps -elf tomcat`
结合管道操作和grep命令进行过滤，用于查询某一个进程的信息
`ps -elf | grep tomcat`

### 二、文件操作

1、tail命令
tail 命令可用于查看文件的内容，语法为
`tail [param] [filename]`
其中param可为：
- -f ：循环读取
- -q ：不显示处理信息
- -v ：显示详细的处理信息
- -c [数目]： 显示的字节数 `tail -c 24 file_name`
- -n [行数]： 显示文件的尾部 n 行内容 `tail -n 2 file_name`
- –pid=PID ：与-f合用,表示在进程ID,PID死掉之后结束
- -q, --quiet, --silent ：从不输出给出文件名的首部
- -s, --sleep-interval=S ：与-f合用,表示在每次反复的间隔休眠S秒
2、ll -ah
- ll -ah命令，可以用于查看文件情况
- ll -ah

### 三、网络通信

1、netstat
netstat命令是用于监控进出网络的包和网络接口统计的命令行工具

语法：`netstat [param]`
param参数可以为：
- -h : 查看帮助
- -r : 显示路由表
- -i : 查看网络接口
2、重启网络
设置了linux网络，需要重启网络，可以用命令：
`service network restart`
3、SELinux
SELinux全称是 Security-Enhanced Linux，它是由美国国家安全局（NSA）贡献的，它为 Linux 内核子系统引入了一个健壮的强制控制访问Mandatory Access Control架构。详情可以参考SELinux 入门，SELINUX工作原理
其实SELinux的功能也就是类似于防火墙的功能，不过安全相对比较好，ok，所以本博客介绍一下SELinux的使用命令
查看selinux状态
`getenforce`
临时禁用SELINUX(学习用的linux才可以禁用，生产的不建议禁用SELINUX)
`setenforce`

永久禁用SELINUX(学习用的linux才可以禁用，生产的不建议禁用SELINUX)

 **将SELINUX=enforce改成SELINUX=disabled**
`vi /etc/selinux/config`

4、防火墙
查询linux系统防火墙开启状态

`firewall-cmd --state`
临时关闭防火墙(学习用的linux才可以禁用，生产的不建议禁用SELINUX)
`systemctl stop firewalld.service`
永久关闭防火墙(学习用的linux才可以禁用，生产的不建议禁用SELINUX)
`systemctl disable firewalld.service`

### 四、系统管理

1、uname
uname命令用于查看内核版本

2、ip addr
查看linux的ip地址：可以用命令
`ip addr`

### 五、基本操作

#### 5.1 Linux关机命令

```shell
[-r] 重启计算器。
[-h] 关机后关闭电源〔halt〕。
[-c] cancel current process取消目前正在执行的关机程序。
[-time] 设定关机〔shutdown〕前的时间。
shutdown -h  now  = 立刻关机
shutdown -h  时间  = 时间关机
shutdown -r  now  = 立即重启
shutdown -h  10   = 十分钟后关机
```

`halt`单独使用等同与`shutdown -h`,可能导致Linux系统死机  
`poweroff`会发送一个ACPI信号来通知系统关机  
`init`进程一共分为7个级别，0和6代表关机和重启  
`reboot`执行重启命令  

#### 5.2基本命令

1. `pwd`:查看路径
2. `cd`:切换目录
3. `mkdir`:创建目录；`mkdir -p /123/123`，递归创建目录
4. `tree`:以树形结构展示目录结构，`tree -L`:指定层数，`tree -d`：只显示目录
5. `ls`:`-l,-a,-d`,长格式显示，显示所有文件，显示目录
6. `cp`:`-r, -i, -a`,递归复制，是否覆盖确认，相当于dpr -p保持文件或目录树形
7. `rm`:`-r,-f`,递归删除，强制删除
8. `alias`:更改别名；`unalias`删除别名

    ```linux
    [root@www /]# alias ls='echo 看个锤子啊，笨蛋不配看内容'
    [root@www /]# ls
    看个锤子啊，笨蛋不配看内容
    [root@www /]# unalias ls
    [root@www ~]# ls
    anaconda-ks.cfg
    ```

9. `mv`:`-t`,把所用源参数移动到目录中，在相同目录中使用相当于改名，不同目标相当于移动
10. `echo`:`-h,-e,\t,\n`,不换行，支持转义，top，回车
11. `touch`:创建文件或更新文件时间戳
12. `cat`:`-n`,显示行号，查看文件内容
13. `head/tail`:输出头部/尾部文件 `-n`,显示行数
14. `tr`:替换或删除字符，仅把文件输出出来，不改变文件内容

    ```linux
    [root@yu yuxi]# cat 123
    999999888888
    [root@yu yuxi]# tr '9' '1' < 123
    111111888888
    [root@yu yuxi]# cat 123
    999999888888
    ````

15. `grep`\:\(awk, sed, grep):文本处理工具。grep中常用格式为`grep [option] mode [file]`. grep家族总共有三个：`grep，egrep，fgrep`.

参数 | 用途
-|-
--color = auto| 过滤的内容加颜色
-v | 取反
-i | 不区分大小写
-n | 显示行号
-w | 按单词位单位过滤
-o | 只输出匹配的内容
-E | 相当于egrep(过滤多个参数）
-A | 显示过滤字符串和它之后多少行
-B | 显示过滤字符串和它之前多少行
-C | 显示过滤字符串和它之前之后多少行

```linux
[root@yu yuxi]# grep -A 2 '15' 123
15
16
17
[root@yu yuxi]# grep -C 2 '15' 123
13
14
15
16
17
[root@yu yuxi]# grep -B 2 '15' 123
13
14
15
[root@yu yuxi]# grep -n '15' 123
15:15
[root@yu yuxi]# grep '15' 123
15
[root@yu yuxi]# grep '1' 123
1
10
11
[root@yu yuxi]# grep -o '1' 123
1
1
1
[root@yu yuxi]# grep -w '1' 123
1
[root@yu yuxi]# egrep -v "^[1-9]$|[1-2][0-9]" 123
30
```

16. `file`:查看文件类型
17. `ln`:创建软硬连接，`-s`创建软链接
18. `which`:查询命令所在路径
19. `find`:目录下查找
    参数|用途
    -|-
    -name| 按文件名查找
    -type| 按文件类型查找
    -exec| 对搜索结果再查找
    -mtime|按修改时间查找

    ```linux
    [root@yu xuexi]# find / -name cp
    /usr/bin/cp
    [root@yu xuexi]# find /yuxi/ -type f
    /yuxi/xuexi/ruanlianjie.txt
    /yuxi/shangke/123.txt
    ```

20. `xargs`:从标准输入执行命令.
    参数|用途
    -n|数字，把几个数字一组
    -d|指定分隔符，默认空格
    -i|把{}当作前面查找的结果

21. `id`:查看用户uid/gid.
22. `whoami/useradd`:查看用户/添加普通用户
23. `stat`:查看文件属性
24. `date`:显示系统时间和日期 `-s`修改时间，`-d`只能过去或未来格式
25. `runlevel`:查看运行等级
26. `init`:切换运行级别
27. `hostname`:修改主机名
28. `tar`:压缩打包
    参数|用途
    -|-
    -z| 压缩
    -c| 创建
    -v| 输出打包过程
    -f| 文件
    -t| 查看文件
    -C| 指定解压路径
    -x| 解压
    -h| 跟随软连接
    -exclude| 排除不打包文件
    -X| 从文件中排除不打包的文件
29. `df`:查看文件系统,`-i`,inode信息，`-h`,block信息
30. `blkid`:查看磁盘文件UUID信息
31. `ifdown/ifup`:指定某个网卡激活启动/关闭
32. `telnet`:查看服务是否开启
33. `uniq / sort`检查及删除文本文件中重复出现的行列/文本文件内容加以排序：
sort几个常用参数：
注意uniq命令只能筛选两行在一起的数据，分开无法筛选，筛选前先排序
    参数|用途
    -|-
    uniq|
    -c| 在每列旁边显示该行重复出现的次数
    -d| 仅显示重复出现的行列
    -u| 仅显示出一次的行列
    sort|
    -b| 忽略每行前面开始出的空格字符
    -r| 以相反的顺序来排序
    -n| 依照数值的大小排序
34. `wc`：统计，用于计算数字
35. 查看硬件信息大礼包
    命令|用途
    -|-
    lscpu| 查看cpu使用情况
    free| 查看内存使用情况
    w| 查看负载使用情况
    top| 查看负载使用情况
    uptime| 查看负载使用情况
36. `kill`:删除执行中的程序
37. `du`:显示目录或文件的大小
38. `ps`:显示进程状态