#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t full,empty;
pthread_mutex_t mutex;
int buffer[5];
int count =0;

void *producer(void* args){
    long int ind = (long int) args;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count] = rand()%10;
    count++;
    printf("Producer %ld: produced item %d\n",ind+1,buffer[count]);
    sleep(2);
    pthread_mutex_unlock(&mutex);
    
    sem_post(&full);
    pthread_exit(NULL);
}

void *consumer(void* args){
    long int ind = (long int) args;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    count--;
    buffer[count] = rand()%10;
    printf("consumer %ld: consumed item %d\n",ind+1,buffer[count]);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    pthread_exit(NULL);
}


int main(){
    int np,nc;
    printf("Enter no. of prod: ");
    scanf("%d",&np);
    printf("Enter no. of cons: ");
    scanf("%d",&nc);
    pthread_t p[10],c[10];

    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);
    
    unsigned long int l,j;

    for(l=0;l<np;l++){
        pthread_create(&p[l],NULL,producer,(void*)l);
    }
    for(j=0;j<nc;j++){
        pthread_create(&c[j],NULL,consumer,(void*)j);
    }
    for(int i=0;i<np;i++){
        pthread_join(p[i],NULL);
    }
    for(int i=0;i<nc;i++){
        pthread_join(c[i],NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}