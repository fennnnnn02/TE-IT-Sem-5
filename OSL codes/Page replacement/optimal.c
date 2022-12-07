#include<stdio.h>
#include<stdlib.h>

int future(int page[],int n,int p,int i){
    for(int k=i+1;k<n;k++){
        if(p==page[k] ) return k;
    }
    return 1000;
}

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
        for(int j=0;j<f;j++){
            if(page[i]==ff[j]) val=0;
        }
        if(val) {
            //printf("\n%d\n",page[i]);
            if(k<f){
                ff[k] = page[i];
                k++;
            }
             else{
            //printf("\n%d\n",page[i]);
            int ind,minn=-1;
            for(int y=0;y<f;y++){
                if(future(page,n,ff[y],i)>minn){
                    minn = future(page,n,ff[y],i);
                    ind = y;
                }
            }
            ff[ind] = page[i];
        }
        }
       
        for(int j=0;j<f;j++){
            printf("%d\t",ff[j]);
        }
        if(val)printf("Page fault\n");
        else printf("Page hit\n");
    }
}