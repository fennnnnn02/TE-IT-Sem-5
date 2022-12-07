#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex,wr;
int a=10;
int readcount=0;

void* reader(void* args){
	long int i = (long int)args;
	pthread_mutex_lock(&mutex);
	printf("\nReader %ld entered CS",i+1);
	readcount++;
	pthread_mutex_unlock(&mutex);
	
	if(readcount==1)
		pthread_mutex_lock(&wr);
		
	printf("\nReader %ld read %d",i+1,a);
	sleep(1);
	pthread_mutex_lock(&mutex);
	printf("\nReader %ld exited CS",i+1);
	readcount--;
	pthread_mutex_unlock(&mutex);
	
	if(readcount==0) pthread_mutex_unlock(&wr);
	
	

}
void* writer(void* args){
	long int i = (long int)args;
	
	pthread_mutex_lock(&wr);
	printf("\nWriter %ld entered CS",i+1);
	printf("\nWriter %ld wrote %d",i+1,++a);
	printf("\nWriter %ld exited CS",i+1);
	sleep(1);
	pthread_mutex_unlock(&wr);
}


int main(){
	int r=5,w=5;
	long int l,j;
	
	pthread_t rr[10],ww[10];
	
	pthread_mutex_init(&mutex,NULL);
	pthread_mutex_init(&wr,NULL);
	
	for(l=0;l<r;l++){
		pthread_create(&rr[l],NULL,reader,(void*)l);
	}
	for(j=0;j<w;j++){
		pthread_create(&ww[j],NULL,writer,(void*)j);
	}
	for(int i=0;i<r;i++){
		pthread_join(rr[i],NULL);
	}
	for(int i=0;i<w;i++){
		pthread_join(ww[i],NULL);
	}
	
	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&wr);
	
}