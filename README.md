# xv6-OS

Contribution: Mutex and Futex Implementation
As part of the development team, I was responsible for designing and implementing mutex (mutual exclusion locks) and futex (fast userspace mutex) mechanisms in xv6. These additions introduced synchronization primitives to support thread-safe operations and improve concurrency handling in user and kernel space.

Mutex: Provided basic locking for critical sections by adding lock acquisition and release system calls.

Futex: Implemented a lightweight, performance-optimized synchronization mechanism using sleep/wakeup queues and minimal kernel interaction, reducing system call overhead for uncontested locks.

These features enhanced the ability of xv6 to manage concurrent processes and threads more efficiently, preparing the system to better simulate real-world multiprocessor behavior.

