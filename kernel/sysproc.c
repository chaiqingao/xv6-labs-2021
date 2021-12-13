#include "types.h"
#include "riscv.h"
#include "param.h"
#include "defs.h"
#include "date.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  if(argaddr(0, &p) < 0)
    return -1;
  return wait(p);
}

uint64
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;


  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}


#ifdef LAB_PGTBL
int
sys_pgaccess(void)
{
  // lab pgtbl: your code here.
  uint64 va;
  int num;
  uint res = 0;
  uint64 user_res;
  if(argaddr(0, &va) < 0)
    return -1;
  if(argint(1, &num) < 0)
    return -1;
  if(num > 32 || num <= 0)
    return -1;
  if(argaddr(2, &user_res) < 0)
    return -1;
  struct proc* p = myproc();
  pagetable_t pagetable;
  pte_t *pte;
  
  for(int i = 0; i < num; i++){
    if (va >= MAXVA)
      return -1;
      
    pagetable = p->pagetable;
    for(int level = 2; level > 0; level--) {
      pte = &pagetable[PX(level, va)];
      if(!(*pte & PTE_V))
        return -1;
      pagetable = (pagetable_t)PTE2PA(*pte);
    }
    pte = &pagetable[PX(0,va)];
    va += PGSIZE;
    if(*pte & PTE_A)
    {
      res |= 1 << i;
      *pte ^= PTE_A;
    }
  }
  
  copyout(p->pagetable, user_res, (char *)&res, sizeof(res));
  return 0;
}
#endif

uint64
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
