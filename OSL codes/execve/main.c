#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
        }
    }
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }printf("\n");
}

int main(){

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    bubblesort(a,n);
    printarr(a,n);

    char * argv[n+2];
    argv[n+1] = NULL;
    argv[0] = "main";

    for(int i=1;i<n+1;i++){
        argv[i] = malloc(10);
        snprintf(argv[i],10,"%d",a[i-1]);
    }

    execve("child",argv,NULL);
}