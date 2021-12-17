# xv6-labs-2021

[MIT 6.S081: Operating System Engineering / Fall 2021](https://pdos.csail.mit.edu/6.828/2021/index.html) 课程实验

## 环境配置

### Debian / Ubuntu / WSL

```shell
$ sudo apt-get update && sudo apt-get upgrade
$ sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

### 其他

参考 [Tools Used in 6.S081](https://pdos.csail.mit.edu/6.828/2021/tools.html) 

## 完成进度

> **4 / 10**

- [x] [Lab: Xv6 and Unix utilities](doc/Xv6-and-Unix-utilities.md) (分支：`util`)
- [x] [Lab: system calls](doc/system-calls.md) (分支：`syscall`)
- [x] [Lab: page tables](doc/page-tables.md) (分支：`pgtbl`)
- [x] [Lab: traps](doc/traps.md) (分支：`traps`)
- [ ] Lab: Copy-on-Write Fork for xv6
- [ ] Lab: Multithreading
- [ ] Lab: networking
- [ ] Lab: locks
- [ ] Lab: file system
- [ ] Lab: mmap
