#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
    int i;
    void *shared_memory;
    char buff[100];
    int shmid = shmget((key_t)1111,1024,0666 | IPC_CREAT);
    printf("key of shared memory is %d\n", shmid);

    shared_memory = shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    printf("Enter data: ");
    fgets(buff,100,stdin);
    strcpy(shared_memory,buff);
    printf("You wrote: %s\n",(char*)shared_memory);
}