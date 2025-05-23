#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
	return fork();
}

int
sys_exit(void)
{
	exit();
	return 0; // not reached
}

int
sys_wait(void)
{
	return wait();
}

int
sys_kill(void)
{
	int pid;

	if (argint(0, &pid) < 0) return -1;
	return kill(pid);
}

int
sys_getpid(void)
{
	return myproc()->pid;
}

int
sys_sbrk(void)
{
	int addr;
	int n;

	if (argint(0, &n) < 0) return -1;
	addr = myproc()->sz;
	if (growproc(n) < 0) return -1;
	return addr;
}

int
sys_sleep(void)
{
	int  n;
	uint ticks0;

	if (argint(0, &n) < 0) return -1;
	acquire(&tickslock);
	ticks0 = ticks;
	while (ticks - ticks0 < n) {
		if (myproc()->killed) {
			release(&tickslock);
			return -1;
		}
		sleep(&ticks, &tickslock);
	}
	release(&tickslock);
	return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
	uint xticks;

	acquire(&tickslock);
	xticks = ticks;
	release(&tickslock);
	return xticks;
}
int sys_cm_create_and_enter(void)
{
	return cm_create_and_enter();
}

int sys_cm_setroot(void){
	char * path; 
	int path_len;

	if(argint(0, (int*)&path_len) < 0 || argptr(1, (void *)&path, sizeof(char*)) < 0) return -1;
	return cm_setroot(path, path_len);
}

int sys_cm_maxproc(void){
	int nproc; 

	if(argint(0, (int*)&nproc) < 0) return -1; 
	return cm_maxproc(nproc); 
}

int
sys_shm_get(void){
    char * name;
    int addr;
    if(argstr(0,&name) < 0) return -1;
    if(name == 0) return -1;
    addr = myproc()->sz;
    if (sm_growproc(name) < 0) return -1;
    return addr;
}

int
sys_shm_rem(void){
    //remove refrence in this proccess. 
    char * name;

    if(argstr(0,&name) < 0) return -1;
    return sm_remove(name);
}


//adding scheduling system call here 
int sys_prio_set(void)
{
	int pid, priority;
	if(argint(0,&pid) <0 ||argint(1,&priority) < 0) return -1;
	return prio_set(pid, priority);
}

//add system call to print priority (for debugging)
int sys_print_prio(void){
	int pid; 
	if(argint(0, &pid) < 0) return -1;
	return print_prio(pid);
}

int sys_create_mutex(void){
	// I am extracting an integer argument 
	// where is it is successful I will store the integer value in the type variable  
	// yet if we fail then we return -1 

	// creating the name of our mutex
	char * name; 
	
	if (argptr(0, &name, sizeof(char * )) < 0){
		return -1; 
	}
	
    return create_mutex(name);
 }

int sys_deleting_mutex(void){
	int muxid; 
	
	if (argint(0, &muxid) < 0){
		return -1; 
	}
	// TODO: call the function in proc.c 
	deleting_mutex(muxid); 

	return 0;
	
}

int sys_locking_mutex(void){
	int muxid; 
	
	if (argint(0, &muxid) < 0){
		return -1; 
	}
	// TODO: call the function in proc.c 
	locking_mutex(muxid); 

	return 0;
}

int sys_unlocking_mutex(void){
	int muxid; 
	
	if (argint(0, &muxid) < 0){
		return -1; 
	}
	// TODO: call the function in proc.c 
	unlocking_mutex(muxid); 

	return 0;

}

int sys_wait_cv(void){
	int muxid; 
	
	if (argint(0, &muxid) < 0){
		return -1; 
	}
	// TODO: call the function in proc.c 
	wait_cv(muxid); 

	return 0;

}

int sys_signal_cv(void){
int muxid; 
	
	if (argint(0, &muxid) < 0){
		return -1; 
	}
	// TODO: call the function in proc.c 
	signal_cv(muxid); 

	return 0;
}

// # -------------- End Of Synchronization Implementation -------------- # 
