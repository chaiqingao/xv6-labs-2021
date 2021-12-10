# Lab: Xv6 and Unix utilities

> 原始要求请点 [这里](https://pdos.csail.mit.edu/6.828/2021/labs/util.html)

## 任务

- sleep ([easy](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  调用系统调用`sleep`

- pingpong ([easy](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  调用系统调用`fork`建立子线程，利用`pipe`进行通信

- primes ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))/([hard](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  递归创建子线程，特别要注意使用系统调用`close`及时关闭不需要的`pipe`端口（因为`xv6`的文件描述符最多到`15`）

- find ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  参考`ls.c`实现当前目录下的文件和文件夹遍历，使用递归实现子目录的搜索

- xargs ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  从标准输入读取参数，按照字符`' '`和`'\n'`分隔，遇到`'\n'`则执行一次`exec`系统调用

## 测试结果

```shell
$ make grade
...
make[1]: Leaving directory '/home/chaiq/xv6-labs-2021'
== Test sleep, no arguments == 
$ make qemu-gdb
sleep, no arguments: OK (2.6s) 
== Test sleep, returns == 
$ make qemu-gdb
sleep, returns: OK (0.6s) 
== Test sleep, makes syscall == 
$ make qemu-gdb
sleep, makes syscall: OK (1.1s) 
== Test pingpong == 
$ make qemu-gdb
pingpong: OK (1.0s) 
== Test primes == 
$ make qemu-gdb
primes: OK (0.9s) 
== Test find, in current directory == 
$ make qemu-gdb
find, in current directory: OK (1.0s) 
== Test find, recursive == 
$ make qemu-gdb
find, recursive: OK (1.1s) 
== Test xargs == 
$ make qemu-gdb
xargs: OK (1.0s) 
== Test time == 
time: OK 
Score: 100/100
```