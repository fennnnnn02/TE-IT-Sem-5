#include<stdio.h>
#include<stdlib.h>

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
    for(int i=0;i<f;i++){
        ff[i] = -1;
    }
    int k=0;
    for(int i=0;i<n;i++){
        printf("%d: ",page[i]);
        int val=1;
        int j;
        for(j=0;j<f;j++){
            if(page[i]==ff[j]) {val=0;break;}
        }
        if(val) {
            if(k<f) {ff[k] = page[i];k++;}
            else{
                ff[0] = page[i];
                for(int p=0;p<f-1;p++){
                int temp = ff[p];
                ff[p] = ff[p+1];
                ff[p+1] = temp;
            }
            }
        }
        else{
            for(int p=j;p<f-1;p++){
                int temp = ff[p];
                ff[p] = ff[p+1];
                ff[p+1] = temp;
            }
        }
        for(int j=0;j<f;j++){
            printf("%d\t",ff[j]);
        }
        if(val)printf("Page fault\n");
        else printf("Page hit\n");
    }
}