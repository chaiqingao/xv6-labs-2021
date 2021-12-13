# Lab: page tables

> 原始要求请点 [这里](https://pdos.csail.mit.edu/6.828/2021/labs/pgtbl.html)

## 任务

- Speed up system calls ([easy](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  `kernel/proc.c`文件：在`allocproc`分配页面、在`freeproc`释放页面；在`proc_pagetable`做页表映射、在`proc_freepagetable`取消映射
  
- Print a page table ([easy](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  递归打印即可，注意判断页表项不是叶子节点的方法是`(pte & (PTE_R|PTE_W|PTE_X)) == 0`

- Detecting which pages have been accessed ([hard](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html))
  
  参考`kernel/vm.c`文件的`walk`函数实现虚拟地址到页表项的转换，之后判断`PTE_A`位即可

## 测试结果

```shell
$ make grade
...
make[1]: Leaving directory '/home/chaiq/xv6-labs-2021'
== Test pgtbltest == 
$ make qemu-gdb
(2.5s) 
== Test   pgtbltest: ugetpid == 
  pgtbltest: ugetpid: OK 
== Test   pgtbltest: pgaccess == 
  pgtbltest: pgaccess: OK 
== Test pte printout == 
$ make qemu-gdb
pte printout: OK (0.8s) 
== Test answers-pgtbl.txt == answers-pgtbl.txt: OK 
== Test usertests == 
$ make qemu-gdb
(114.5s) 
== Test   usertests: all tests == 
  usertests: all tests: OK 
== Test time == 
time: OK 
Score: 46/46
```