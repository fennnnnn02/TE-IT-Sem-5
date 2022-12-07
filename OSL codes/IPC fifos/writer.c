#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    int fd1,fd2;
    char* f1 = "myfifo1";
    char* f2 = "myfifo2";
    char a[100],b[100];
    fd1 = open(f1,O_RDONLY);
    read(fd1,a,strlen(a)+1);
    close(fd1);
    printf("Message in fifo1 is: \n%s\n",a);

    int i=0,l=0,w=0,c=0;
    while(a[i]!='\0'){
        if(a[i]=='.' || a[i] =='\n') l++;
        else if(a[i]==' ') w++;
        else c++;
        i++;
    }
    c--;
    printf("here is the info\n");
    printf("No of lines: %d\n", l);
  printf("No of words: %d\n", w);
  printf("No of characters: %d\n", c);

    FILE *tfd = fopen("a.txt","w");
    fprintf(tfd, "Data written in txt file\nInformation about the entered string\n");
  fprintf(tfd, "No of lines: %d\n", l);
  fprintf(tfd, "No of words: %d\n", w);
  fprintf(tfd, "No of characters: %d\n", c);
  fclose(tfd);
  char tempstr[100];

    tfd = fopen("a.txt",'r');
    int i=0;
    while(1){
        if(feof(tfd)) break;
        tempstr[i] = fgetc(tfd);
        i++;
    }
    tempstr[i] = '\0';
    fclose(tfd);

    mkfifo(f2,0666);
    fd2 = open(f2,O_RDONLY);
    write(fd2,tempstr,100+1);
    close(fd2);
    return 0;

}