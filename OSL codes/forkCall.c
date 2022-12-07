# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<sys/types.h>
# include<sys/wait.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }printf("\n");
}

int main(){
    pid_t p;
    p = fork();

    int a[5] = {1,5,2,3,4};

    // Normal

    // if(p>0){
    // 	wait(NULL);
    //     printf("Parent process id: %d\n",getppid())
    //     printf("%s\n","Parent Process");
    //     bubblesort(a,5);
    //     printarr(a,5);
    //     printf("%s\n","exited parent process");
        
    // }
    
    // else{
    //     printf("Child process id: %d\n",getpid())
    // 	printf("%s\n","Child process");
    //     bubblesort(a,5);
    //     printarr(a,5);
    //     printf("%s\n","exited child");
    // }

    // Zombie

    // if(p>0){
    // 	sleep(5);
    //     printf("Parent process id: %d\n",getppid());
    //     printf("%s\n","Parent Process");
    //     bubblesort(a,5);
    //     printarr(a,5);

    //     system("ps -aux | grep %d");
    //     printf("\n");

    //     printf("%s\n","exited parent process");
        
    // }
    
    // else{
    //     printf("Child process id: %d\n",getpid());
    // 	printf("%s\n","Child process");
    //     bubblesort(a,5);
    //     printarr(a,5);

    //     system("ps -aux | grep %d");
    //     printf("\n");

    //     printf("%s\n","exited child");
    // }

    // Orphan 

    if(p>0){
    	
        printf("%s\n","Inside Parent Process");
        printf("Parent process id: %d and Child process id is: %d\n",getppid(),getpid());
        bubblesort(a,5);
        printarr(a,5);

        system("ps -aux | grep %d");
        printf("\n");

        printf("%s\n","exited parent process");
        
    }
    
    else{
        sleep(5);
    	printf("%s\n","Inside Child process");
        printf("Parent process id: %d and Child process id is: %d\n",getppid(),getpid());
        bubblesort(a,5);
        printarr(a,5);

        system("ps -aux | grep %d");
        printf("\n");

        printf("%s\n","exited child");
    }

    return 0;
}