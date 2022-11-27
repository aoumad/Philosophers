# Philosophers
 Philosophers an individual project at 42 about introduction to the basics of process threading, and how work on the same memory space. And learn about mutexes, semaphores, and shared memory.
 
![results.png](https://github.com/aoumad/Philosophers/blob/main/imgs/results.png)

## Table of content
  - [Overview](#overview)
  - [Instructions of the project](#instruction-of-the-project)
  - [Mandatory part](#mandatory-part)
  - [Bonus part](#bonus-part)
  - [Important Resources](#resources)
  
  > **Note**
  > In both parts of mandatory and bonus section we will discuss all the things we will need to know
  >> (Mutexes, Semaphores, Deadlocks, Race condition...)
  
  ![Dinning_philosophers.png](https://github.com/aoumad/Philosophers/blob/main/imgs/Dinning_philosophers.png)
  
  ### Overview
  ---
 Here are the things you need to know if you want to succeed this assignment:
- One or more philosophers sit at a round table.
  There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
  While they are eating, they are not thinking nor sleeping;
  while thinking, they are not eating nor sleeping;
  and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
  philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
  start sleeping. Once awake, they start thinking again. The simulation stops when
  a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying

### Instruction of the project
---

You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:
- Global variables are forbidden!
- Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
- Each philosopher has a number ranging from 1 to number_of_philosophers.
- Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

◦ About the logs of your program:
- Any state change of a philosopher must be formatted as follows:
- timestamp_in_ms X has taken a fork
- timestamp_in_ms X is eating
- timestamp_in_ms X is sleeping
- timestamp_in_ms X is thinking
- timestamp_in_ms X died
◦ Replace timestamp_in_ms with the current timestamp in milliseconds
  and X with the philosopher number.
  
 ◦ A displayed state message should not be mixed up with another message.

 ◦ A message announcing a philosopher died should be displayed no more than 10 ms
  after the actual death of the philosopher.
  
 ◦ Again, philosophers should avoid dying

> **Warning**
>> Your program must not have any data races nor Deadlock issues (we will talk later how to deal with them)

### Mandatory part
---
## Rules

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.

> Now let's discuss all the things we will need to know about to work on our Mandatory part of this project!!
## Concurrent Porgramming
In many situations we need our program to be concurrent rather than sequential, let's take an example!
How many times we opened our Web browser and we opened two tabs, the first one for listening to music and the other one for searching reasons!! EXACTLY this is why we need many times the concurrency Simply it allows a program to perform several tasks simultaneously instead of having to wait for the result of one operation to move onto the next. The operating system itself uses this concept to meet its users expectations. If we had to wait for a song to finish to be able to open our browser, or if we had to restart the computer to kill a program caught in an infinite loop, we’d die of frustration!
 - And this is exactly why we are learning about Threads, but firstly what are threads?

## What is a THREAD?

A thread is a single sequence within a process. Because threads have some of the properties of the processes, they are sometimes called lightweight processes.

![Threads_vs_process.png](https://github.com/aoumad/Philosophers/blob/main/imgs/Threads_vs_process.png)

-As you can see in the image above, Threads are not independent from each other unlike processes. As a result, threads shares with other threads their code section, data section and OS resources like open files and signals. But, like processes, a thread has it's own stack space, register and a program counter (PC).
- But since all of the threads are part of the same process, they share the same virtual memory adress space: the same code, the same heap, the same shared libraries.
- A threads's context has a smaller footprint in terms of resources than the context of a process. Which means that it is much faster for the system to create a thread than it is to create a process. As well as it's quicker in terms of switching from one thread to another, compared to switching from one process to another.

## Why Multithreading?

- Threads are popular way to improve application though parallelism. For example, in a browser, Multiple tabs can be different threads. and Multiple windows that contains many tabs within it can be different processes.
- Earlier, we talked about the stack and the heap, the two kinds of memory available to a thread or process. Distinguishing between these kinds of memory matters because each thread will have its own stack. However, all the threads in a process will share the heap.

![multithreading.png](https://github.com/aoumad/Philosophers/blob/main/imgs/multithreading.png)

## USING POSIX Threads
The standard interface in C to manipulate threads is POSIX with it's <pthread.h> library. It contains around sixty functions to create, detach join and also destroy threads, as well as to manage their shared memory. We will only study a fraction of these in this article. In order to compile a program using this library, we shouldn't forget to link it with -pthread in our Makefile.

### Creating a Thread
 It is used to create a new thread.
 
```c
#include <phtreads.h>
```

```c
int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
```

- Parameters:
 
◦ thread: pointer to an unsigned integer value that returns the thread id of the thread created.

◦ attr: pointer to a structure that is used to define thread attributes like detached state, scheduling   policy, stack address, etc. Set to NULL for default thread attributes.
  
◦ start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter     type of the subroutine must be of type void *. The function has a single attribute but if multiple       values need to be passed to the function, a struct must be used.

◦ arg: pointer to void that contains the arguments to the function defined in the earlier argument

> **Note**
> 💡 The last argument can help us to pass arguments to the function but we can also get results from the function using the second parameter of `pthread_join`

### Waiting:

```c
int pthread_join(pthread_t th, void **thread_return);
```

    Used to wait for the termination of a thread.

**th:** The target thread whose termination you're waiting for.

**thread_return*:*** NULL, or a pointer to a location where the function can store the value passed to *[pthread_exit()](https://www.qnx.com/developers/docs/6.4.0/neutrino/lib_ref/p/pthread_exit.html)* by the target thread.

`pthread_join` does two things:

1. Wait for the thread to finish.
2. Clean up any resources associated with the thread

If you exit the process without joining, then (2) will be done for you by the OS (although it won't do thread cancellation cleanup, just nuke the thread from orbit), and (1) will not. So whether you need to call `pthread_join` depends on whether you need (1) to happen.

If you don't need the thread to run, then as everyone else is saying you may as well detach it. A detached thread cannot be joined (so you can't wait on its completion), but its resources are freed automatically if it does complete.

### Detaching a thread:

```c
int pthread_detach(pthread_t tid);
```
- Used to detach a thread. A detached thread does not require a thread to join on terminating. The resources of the thread are automatically released after terminating if the thread is detached.
- other threads will not be able to kill or wait for this thread with pthread_join

> **Note**
> 💡 The thread by default is created joinable but we can make it detached since creation using the thread attributes.
>> Put in mind that the detached thread can no longer be joinable so the program might exit before its termination to solve this use: pthread_exit();

## Threads and Shared Memory

- One of the greatest qualities of threads is that they all share their process's memory. Each thread does have it's own stack, but the other threads can very easily gain access to it with a simple pointer. What's more, the heap as we saw before and any open file descriptors are totally shared between threads.

- This shared memory and the ease with which a thread can access another thread's memory is clearly has it's own share of danger, that's why you will find many documents that mention that threads can be dangerous. As well as the fact that it can cause nastly synchronization errors.

## The Danger of Race condition

- A race condition occurs when two threads access a shared resources at the same time. The first thread reads from the resource, and the second threads reads the same value from the resource. Then the first thread and second thread perform their operations on the value, and they race to see which thread can write the value last to the shared resource. The value of the thread that writes it's value last is preserved, because the thread is writing over the value that the previous thread wrote in.

> 💡 So is there a way to stop a thread from reading a value while another one modifies it? Yes, thanks to mutexes!

## Mutexes (mutual exclusion)

- A mutex (short for “mutual exclusion”) is a synchronization primitive. It is essentially a lock that allows us to regulate access to data and prevent shared resources being used at the same time.

- We can think of a mutex as the lock of a bathroom door. One thread locks it to indicate that the bathroom is occupied. The other threads will just have to patiently stand in line until the door is unlocked before they can take their turn in the bathroom.

### Declaring a Mutex

Thanks to the <pthread.h> header, we can declare a mutex type variable like this:
```c
pthread_mutex_t    mutex;
```
Before we can use it, we first need to initialize it with the pthread_mutex_init function which has the following prototype:
```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
```
There are two parameters to supply:

- mutex: the pointer to a variable of pthread_mutex_t type, the mutex we want to initialize.
- mutexattr: a pointer to specific attributes for the mutex. We will not worry about this parameter here, we can just say NULL.
 > 💡 The pthread_mutex_init function only ever returns 0.

### Locking and Unlocking a Mutex
In order to lock and unlock our mutex, we need two other functions. Their prototypes are as follows:

```c
int pthread_mutex_lock(pthread_mutex_t *mutex));
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
- If the mutex is unlocked, `pthread_mutex_lock` locks it and the calling thread becomes it's owner. In this case, the function ends immediately. However, If the mutex is already locked by another thread, `pthread_mutex_lock` suspends the execution of the calling thread until the mutex is unlocked.
- The `pthread_mutex_unlock` function unlocks a mutex. The mutex to be unlocked is assumed to be locked by the calling thread, and the function only sets it to unlocked. Let's be careful to note that this function does not check if the mutex is in fact locked and that the calling thread is actually it's owner: a mutex could therefore be unlocked by a thread that did not lock it in the first place. We will need to be careful about arranging `pthread_mutex_lock` and `pthread_mutex_unlock` in our code, otherwise, we might get ``lock order violation`` errors.
> 💡 Both of these functions return 0 for success and an error code otherwise.

### Destroying a Mutex

When we no longer need a mutex, we should destroy it with the following `pthread_mutex_destroy` function:

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

This function destroys an unlocked mutex, freeing whatever resources it might hold. In the LinuxThreads implementation of Posix threads, no resources are associated with mutexes. In this case, pthread_mutex_destroy doesn't do anything other than check that the mutex isn't locked.

### Beware if Deadlocks

However, mutexes can often provoke deadlocks. It's a situation in which each threads waits for resource helf by another thread. For example, there are two philosophers in a simulation, a philosopher with ID = 1 acquired a mutex fork M1 and is waiting for the second mutex fork M2 , Meanwhile the second philosopher with ID = 2 acquired a mutex fork M2 and is waiting for the first Mutex fork M1 to start eating as well. In this situation, the program stays perpentually pending and must be killed.
> 💡 A deadlock can also happen when a thread is waiting for a mutex that it already owns!
- To deal with deadlocks in our project we should lunch philos in a way that half of philos will take the both forks and start eating, which means eather we will leave the odd or even numbers to start the routine.

```c
	if (philo->id & 1)
            usleep(50);
```
> The code above is an example of dealing with Dealocks that i used in my project (i used bitwise AND &)
> you can also use this second approach (modulo approach)
```c
 if (philo->id % 2 = 0)
     usleep(50)
```
## Bonus part
 ### General instructions
 
 The specific rules for the bonus part are:
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process. But the main process should not be a philosopher.

### What is a semaphore?
- A semaphore is in integer variable, shared among multiple processes. The main aim of using a semaphore is process synchronization and access control for a common resource in a concurrent environment.
- The initial value of a semaphore depends on the problem at hand. Usually, we use the number of resources available as the initial value.
- It's a synchronization tool that doesn't require busy waiting. Hence, the operating system doesn't waste the CPU cycles when a process can't operate due to lack od access to a resource.
![Semaphores.png](https://github.com/aoumad/Philosophers/blob/main/imgs/Semaphores.png)

### Semaphore Operations
- A semaphore has two indivisible (atomic) operations, namely: wait and signal or post. These operations are sometimes referred as P and V, or DOWN or UP in some docs.
- In the code that appears here you can clearly see the simplest core use of a semaphore:
![Semaphore.png](https://github.com/aoumad/Philosophers/blob/main/imgs/Semaphore.png)

### Types of Semaphore
In general, there are two types of semaphores:

> 1- **Binary Semaphore**
> 
	- A binary semaphore is a semaphore whose integer value range over 0 and 1.
	- It's nothing, but similar to lock, with two values: 0 and 1. Here 0 means busy, while 1 means free.
	- The idea behind using a binary semaphore is that, it allows only one process at a time to enter the critical section (thus allowing it to access the shared resource)
	- Here, 0 represents that a process or a thread is in the critical section (i.e it is accessing the shared resource), while the other process or thread should wait for it to complete. One the other hand, 1 means that no process is accessing the shared resource, and the critical section is free.
	- It guarantees mutual exclusion since no two processes can be in the critical section at any point in time.
	- Since it is just a variable, which holds an integer value, it cannot guarantee bounded waiting. it might happen, that a process may never get a chance to enter the critical section, which may lead to it's starvation. And we don't want that.
	
> 2- Counting Semaphore
> 
	- A counting semaphore is a semaphore that has multiple values of the counter. The value can range over an unrestricted domain.
	- It is a structure, which comprises a variable, known as a semaphore variable that can take more than two values and a list of task or entity, which is nothing but the process or the thread.
	- The value of the counting semaphore can range between 0 and N, where N is the number of process which is free to enter and exit the critical section.
	- As mentioned, a counting semaphore can allow multiple processes or threads to access the critical section, Hence mutual exclusion is not guaranteed.
	- Since multiple instances of process can acesss the shared resource at any time, counting semaphore guarantees bounded wait. Using such a semaphore, a process which enters the critical section has to wait for the other process to get inside the critical section, implying that no process will starve.

> **Note**
> POSIX semaphores are available in two flavors: named and unnamed.
> > `Named Semaphore` are like process-shared semaphores, except that named semaphores are referenced with a `pathname` rather than a `pshared` value. Named semaphores are sharable by several processes. As well as they have an owner user-ID, group-ID, and a protection mode.

> > `Unnamed semaphore` are allocated in process memory and initialized. Unnamed semaphores might be usable by more than one process, depending on how the semaphore is allocated and initialized. Unnamed semaphore are either private, inherited throught fork(), or are protected by access protections of the regular file in which they are allocated and mapped.

### Initialization
```c
#include <semaphore.h>

sem_t semaphore;
```

### Creating a sem
`sem_open()`
> Create or access a named semaphore

```c
#include <semaphore.h>
#include <fcntl.h>
sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
```

The sem_open() function creates a connection between a named semaphore and a process. Once the connection has been created for the semaphore name specified by the name argument with a call to sem_open(), the process can use the address returned by the call to reference that semaphore.

name → The name of the semaphore that you want to create or access.

oflag → Flags that affect how the function creates a new semaphore. This argument is a combination of:

O_CREAT

This flag is used to create a semaphore if it does not already exist. If O_CREAT  is set and the semaphore already exists, then O_CREAT has no effect, except as noted under the description of the O_EXCL flag.

O_EXCL

If the O_EXCL and O_CREAT flags are set, the sem_open subroutine fails if the semaphore name exists. The check for the existence of the semaphore and the creation of the semaphore if it does not exist are atomic with respect to other processes executing the sem_open subroutine with the O_EXCL and O_CREAT flags set. If O_EXCL is set and O_CREAT is not set, O_EXCL is ignored.

Example:

```c
sem_open("sem", O_CREAT | O_EXCL, 0644, n);
```
> 0644
> 
> > 0: ndicates octal notation, just like 0x indicates hexadecimal notation. So every time you write plain zero in C, it's actually an octal zero (fun fact).
>
> > 6 : (owning) User: read & write
>
> > 4 : Group: read
>
> > 4 : Other: read

### Blocking | Waits:

```c
int sem_wai(sem_t *semaphore);
```
> Return Value : 
> > 0 if success
>
> > -1 if error

### Post | Release:

```c
int sem_post(sem_t *semaphore);
```

> **Return value:** \
>  0 if success. \
>  -1 if error. 
### Closure:

```c
int sem_close(sem_t *sem);
```

closes the named semaphore referred to bysem,  allowing any resources that the system has allocated to the calling process for this semaphore to be freed. ***the semaphore still remains in the system.***

> **Return value:** \
>  0 if success. \
>  -1 if error. 
```c
int sem_unlink(const char *name);
```

removes the named semaphore referred to by name from the system. The semaphore name is removed immediately.  The semaphore is destroyed once all other processes that have the semaphore open close it.

> **Return value:** \
>  0 if success. \
>  -1 if error.
