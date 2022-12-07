#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    printf("Enter total no. of pages: ");
    scanf("%d",&n);
    int page[n];
    printf("Enter pages: ");
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }

    int f;
    printf("Enter total no. of frames: ");
    scanf("%d",&f);

    int ff[f];
    int k=0;
    for(int i=0;i<f;i++){
        ff[i] = -1;
    }
    for(int i=0;i<n;i++){
        printf("%d: ",page[i]);
        int val=1;
        for(int j=0;j<f;j++){
            if(page[i]==ff[j]) val=0;
        }
        if(val) {
            ff[k] = page[i];
            k++;
            if(k==f) k = 0;
        }
        for(int j=0;j<f;j++){
            printf("%d\t",ff[j]);
        }
        if(val)printf("Page fault\n");
        else printf("Page hit\n");
    }
}