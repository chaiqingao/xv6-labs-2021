# Lab: system calls

> 原始要求请点 [这里](https://pdos.csail.mit.edu/6.828/2021/labs/syscall.html)

## 任务

- System call tracing ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  在`struct proc`中存储一个`mask`记录要跟踪的系统调用，并在`fork`时拷贝到子程序里，之后每次系统调用时都判断系统调用号是否在`mask`里，若在就打印

- Sysinfo ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  计算空闲内存在`kalloc.c`中实现，通过遍历`kmem.freelist`得到；计算程序数量在`proc.c`中实现，通过遍历`proc`数组得到

## 测试结果

```shell
$ make grade
...
make[1]: Leaving directory '/home/chaiq/xv6-labs-2021'
== Test trace 32 grep == 
$ make qemu-gdb
trace 32 grep: OK (2.2s) 
== Test trace all grep == 
$ make qemu-gdb
trace all grep: OK (0.9s) 
== Test trace nothing == 
$ make qemu-gdb
trace nothing: OK (1.0s) 
== Test trace children == 
$ make qemu-gdb
trace children: OK (11.2s) 
== Test sysinfotest == 
$ make qemu-gdb
sysinfotest: OK (1.6s) 
== Test time == 
time: OK 
Score: 35/35
```