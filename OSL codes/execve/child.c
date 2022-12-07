#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<strings.h>

int main(int argc,char*argv){
    printf("Child program name: ");
	printf("%s\n",argv[0]);
    printf("argc is: %d",argc);

    int a[argc];

    for(int i=1;i<argc;i++){
        a[i] = atoi(argv[i]);
        printf("%d\n",a[i]);
    }
}