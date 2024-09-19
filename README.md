__________________philosophers___________________
***I never thought philosophy would be so deadly**

Dining Philosophers Simulation

This project implements the Dining Philosophers Problem using C, with threads and mutexes for synchronization.

The simulation demonstrates how philosophers alternate between eating, sleeping, and thinking while sharing limited resources (forks).

The challenge lies in ensuring philosophers don't starve and no deadlocks occur.

Problem Overview

Philosophers sit at a round table with a bowl of spaghetti in the center. Each philosopher must eat but can only do so using two forks (one in each hand).

The goal is to synchronize the philosophers' actions so that they all get a chance to eat without dying of starvation.


Key concepts:


+ Philosophers: They alternate between three states: thinking, eating, and sleeping.
  
+ Forks: Shared resources between neighboring philosophers.
  
+ Synchronization: Using threads to represent philosophers and mutexes to handle fork access and prevent race conditions.


Project Structure :

+ run_cycle.c: Contains the core logic for philosopher actions (eating, sleeping, thinking).
+ Makefile: Handles compilation with necessary flags like -Wall, -Wextra, -Werror.
+ pthread: Used to create and manage philosopher threads.
+ Mutexes: Applied to protect shared resources (forks) and prevent data races.


How It Works :

1- Each philosopher is represented by a thread.
2- Mutexes are used to synchronize fork access, ensuring only one philosopher can pick up a fork at a time.
3- The program tracks the state of each philosopher (eating, sleeping, thinking) and stops the simulation if a philosopher starves.

-----Synchronization Logic-----

Eating:

Each philosopher follows a different method depending on whether their ID is even or odd:


-> Even philosophers: Take the right fork first, then the left.

-> Odd philosophers: Take the left fork first, then the right. Once the philosopher has both forks, they eat for a set period (t_eat), then release the forks.Sleeping and Thinking:

 Sleeping and Thinking:
 
 After eating, a philosopher sleeps for t_sleep and then transitions to thinking. A small delay (usleep) is applied to stagger the actions of even and odd philosophers, reducing contention for forks.


 Routine:
 
Each philosopher repeatedly follows the routine of eating, sleeping, and thinking until the simulation ends (when a philosopher dies or all have eaten a specified number of times).

Compilation and Execution
To compile and run the project:

## Compilation and Execution

To compile and run the project:

```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```
Rules and Constraints :

---Global variables are forbidden.

--Data races must be avoided.

-The simulation must log philosopher actions in real-time (eating, sleeping, thinking, taking forks, or dying).
