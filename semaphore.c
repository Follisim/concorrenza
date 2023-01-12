
#include <sys/sem.h>
#include <sys/types.h>


typedef sem_t semaphore; // sem_t is a type defined in the POSIX standard
semaphore *make_semaphore(int value); // create a semaphore with initial value
void P(semaphore *sem); // P is the "wait" operation
void V(semaphore *sem); // V is the "signal" operation

semaphore *make_semaphore(int value){
    semaphore *sem = check_malloc(sizeof(semaphore));
    int n = sem_init(sem, 0, value);//sem_init return 0 if it succeeds and -1 if it fails
    if (n != 0) perror_exit("sem_init failed");
    return sem;
}


void P(semaphore *sem){
    int n = sem_wait(sem);
    if (n != 0)
        perror_exit("sem_post failed");
}

void V(semaphore *sem){
    int n = sem_post(sem);
    if (n != 0)
        perror_exit("sem_post failed");
}