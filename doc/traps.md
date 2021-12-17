# Lab: traps

> 原始要求请点 [这里](https://pdos.csail.mit.edu/6.828/2021/labs/traps.html)

## 任务

- RISC-V assembly ([easy](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  参考 [xv6-riscv-book](https://pdos.csail.mit.edu/6.828/2021/xv6/book-riscv-rev2.pdf) 回答
  
- Backtrace ([moderate](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  不断循环找上层调用的`return address`，注意用`PGROUNDDOWN`和`PGROUNDUP`确定边界结束循环

- Alarm ([hard](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  `trapframe->epc`记录了返回用户空间的地址，当计时结束时将其设为调用函数`handler`，注意在进程中保存原始的`trapframe`并在`sigreturn`中释放。同时要注意在`kernel/proc.c`中对新变量的初始化（`allocproc`）和释放（`freeproc`）

## 测试结果

```shell
$ make grade
...
make[1]: Leaving directory '/home/chaiq/xv6-labs-2021'
== Test answers-traps.txt == answers-traps.txt: OK 
== Test backtrace test == 
$ make qemu-gdb
backtrace test: OK (2.2s) 
== Test running alarmtest == 
$ make qemu-gdb
(3.9s) 
== Test   alarmtest: test0 == 
  alarmtest: test0: OK 
== Test   alarmtest: test1 == 
  alarmtest: test1: OK 
== Test   alarmtest: test2 == 
  alarmtest: test2: OK 
== Test usertests == 
$ make qemu-gdb
usertests: OK (109.8s) 
== Test time == 
time: OK 
Score: 85/85
```