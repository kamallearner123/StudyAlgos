#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


pthread_t t1, t2;
int val1=1;

pthread_mutex_t mut;

void * fun_odd(void *data) {
   int val_max = atoi((char *)data);
    
   while(1) {
        pthread_mutex_lock(&mut);
        
        if (val1>val_max) {
            pthread_mutex_unlock(&mut);
            break;
        }
       
        if (val1%2 == 1) {
            printf("Thread1: %d \n", val1);
            fflush(stdout);
            val1 +=1;
        }
        pthread_mutex_unlock(&mut);
   }
    pthread_join(t1, NULL);
   pthread_exit(NULL);
}

void * fun_even(void *data) {
   int val_max = atoi((char *)data);
   while(1) {
        pthread_mutex_lock(&mut);
        if (val1>val_max) {
            pthread_mutex_unlock(&mut);
            break;
        }
        
        if (val1%2 == 0) {
            printf("Thread2: %d \n", val1);
            fflush(stdout);
            val1 += 1;
        }
        pthread_mutex_unlock(&mut);
   }
   pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("less number of argc\n");
    }
    pthread_mutex_init(&mut, NULL);

    pthread_create(&t1, NULL,fun_odd, argv[1]);
    pthread_create(&t2, NULL,fun_even, argv[1]);
    
    int *result;
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mut);
}

