#include<stdio.h>
#include<stdlib.h>

void bsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){

    int n,maxrange,headpos;

    printf("Enter the no of disk scheduling requests: ");
    scanf("%d",&n);
    printf("Enter the maximum range of the disk: ");
    scanf("%d",&maxrange);
    printf("Enter the initial head position: ");
    scanf("%d",&headpos);

    int disk[n];

    int left[30],right[30];
    
    int l=0;int r=1;

    for(int i=0;i<30;i++){
        left[i] = 10000;
        right[i] = 10000;
    }
    right[0] = maxrange-1;
    printf("Enter disk elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&disk[i]);
    }

    for(int i=0;i<n;i++){
        if(disk[i]<headpos) {
            left[l] = disk[i];
            l++;
        }
        else {
            right[r]=disk[i];
            r++;
        }
    }

    bsort(right,30);
    bsort(left,30);

    

    for(int i=0;i<30;i++){
        if(right[i]!=10000) printf("\n%d",right[i]);
        else break;
        
    }
    for(int i=30;i>=0;i--){
       if(left[i]!=10000)printf("\n%d",left[i]);
       
    }

}