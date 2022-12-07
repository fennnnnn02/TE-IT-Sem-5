#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    int fd1,fd2;
    char *f1 = "myfifo1";
    char *f2 = "myfifo2";
    mkfifo(f1,0666);

    char s[100],buffer[100];
    printf("Please enter a string: ");
    fgets(s,100,stdin);

    fd1 = open(f1,O_WRONLY);

    write(fd1,s,strlen(s)+1);
    close(fd1);

    fd2 = open(f2,O_RDONLY);
    write(fd2,buffer,100+1);
    close(fd2);
}