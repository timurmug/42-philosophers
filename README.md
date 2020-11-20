# Philosophers
#### 42 project about basics of threading a process and how to work on the same memory space

</br>

* **First task**: philosopher with threads and mutex
	* One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
	* Should protect the forks state with a mutex for each of them.
	* Each philosopher should be a thread.
* **Second task**: philosopher with threads and semaphore
	* All the forks are in the middle of the table.
	* They have no states in memory but the number of available forks is represented by a semaphore.
	* Each philosopher should be a thread.
* **Third task**: philosopher with processes and semaphore
	* All the forks are in the middle of the table.
	* They have no states in memory but the number of available forks is represented by a semaphore.
	* Each philosopher should be a process and the main process should not be a philosopher.

</br>

##  Each program should have the same options: 
* **number_of_philosophers**: is the number of philosophers and also the number of forks
* **time_to_die**: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
* **time_to_eat**: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
* **time_to_sleep**: is in milliseconds and is the time the philosopher will spend sleeping.
* **number_of_times_each_philosopher_must_eat**: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

</br>

## Threads
| Function | Description |
| --- | --- |
| pthread_create(&thread_var, NULL, func_name, &arg_to_func_in_void) | create new thread |
| pthread_join(thread_var, NULL) | main thread is waiting thread |

</br>

## Mutexes
| Function | Description |
| --- | --- |
| pthread_mutex_init(&mutex_var, NULL) | init mutex |
| pthread_mutex_lock(&mutex_var) | increment mutex by 1 |
| pthread_mutex_unlock(&mutex_var) | decrement mutex by 1 |
| pthread_mutex_destroy(&mutex_var) | free resources allocated for mutex |

</br>

## Semaphores
| Function | Description |
| --- | --- |
| sem_unlink("file_name") | unlink old semaphore |
| sem_var = sem_open("file_name", O_CREAT, NULL, 7) | open semaphore "file_name", assign value to 7 and save in sem_var |
| sem_post(sem_var) | increment semaphore by 1 |
| sem_wait(sem_var) | decrement semaphore by 1 |
| sem_close(sem_var) | close semaphore |
