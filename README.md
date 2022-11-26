# Philosophers
 Philosophers an individual project at 42 about introduction to the basics of process threading, and how work on the same memory space. And learn about mutexes, semaphores, and shared memory.


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

