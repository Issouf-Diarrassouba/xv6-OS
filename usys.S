#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(cm_create_and_enter)
SYSCALL(cm_setroot)
SYSCALL(cm_maxproc)
SYSCALL(shm_get)
SYSCALL(shm_rem)
SYSCALL(prio_set)
SYSCALL(print_prio)
YSCALL(create_mutex)
SYSCALL(deleting_mutex)
SYSCALL(locking_mutex)
SYSCALL(unlocking_mutex)
SYSCALL(wait_cv)
SYSCALL(signal_cv)