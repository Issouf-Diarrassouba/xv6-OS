struct stat;
struct rtcdate;

// system calls
int   fork(void);
int   exit(void) __attribute__((noreturn));
int   wait(void);
int   pipe(int *);
int   write(int, void *, int);
int   read(int, void *, int);
int   close(int);
int   kill(int);
int   exec(char *, char **);
int   open(char *, int);
int   mknod(char *, short, short);
int   unlink(char *);
int   fstat(int fd, struct stat *);
int   link(char *, char *);
int   mkdir(char *);
int   chdir(char *);
int   dup(int);
int   getpid(void);
char *sbrk(int);
int   sleep(int);
int   uptime(void);
int   cm_create_and_enter(void); 
int cm_setroot(char *, int );
int cm_maxproc(int);
char * shm_get(char * name);
int   shm_rem(char * name);
int   prio_set(int pid, int priority);
int	  print_prio(int pid);
int create_mutex(char *);
void deleting_mutex(int);
void locking_mutex(int);
void unlocking_mutex(int);
void wait_cv(int);
void signal_cv(int);

// ulib.c
int   stat(char *, struct stat *);
char *strcpy(char *, char *);
void *memmove(void *, void *, int);
char *strchr(const char *, char c);
int   strcmp(const char *, const char *);
void  printf(int, char *, ...);
char *gets(char *, int max);
uint  strlen(char *);
void *memset(void *, int, uint);
void *malloc(uint);
void  free(void *);
int   atoi(const char *);
