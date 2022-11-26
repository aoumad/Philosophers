# Philosophers
 Philosophers an individual project at 42 about introduction to the basics of process threading, and how work on the same memory space. And learn about mutexes, semaphores, and shared memory.

![Dinning_philosophers.png](https://github.com/aoumad/Philosophers/blob/main/imgs/Dinning_philosophers.png)

## Table of content
  - [Overview](#overview)
  - [Instructions of the project](#instruction-of-the-project)
  - [Mandatory part](#mandatory-part)
  - [Bonus part](#bonus-part)
  - [Important Resources](#resources)
  
  > **Note**
  > In both parts of mandatory and bonus section we will discuss all the things we will need to know
  >> (Mutexes, Semaphores, Deadlocks, Race condition...)
  
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

## Mutexes (mutual exclusion)
