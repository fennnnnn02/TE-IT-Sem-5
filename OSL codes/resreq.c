#include<stdlib.h>
#include<stdio.h>

const int n=5, m=3;

int alloc[5][3] = {{0,1,0},
                   {2,0,0},
                   {3,0,2},
                   {2,1,1},
                   {0,0,2}};

int maxx[5][3] = { { 7, 5, 3 }, 
              { 3, 2, 2 }, 
              { 9, 0, 2 }, 
              { 2, 2, 2 }, 
              { 4, 3, 3 } }; 

int avail[3] = { 3, 3, 2 };


int need[5][3];

int safety(){
    int work[3],finish[5];
    for(int i=0;i<m;i++){
        work[i] = avail[i];
    }

    for(int j=0;j<n;j++){
        finish[j] = 0;
    }

    for(int i=0;i<n;i++){
        int val = 1;
        for(int j=0;j<m;j++){
            if(need[i][j]>work[j]) {
                val = 0;
                break;
            }
        }

        if(!finish[i] && val){
            finish[i] = 1;
            printf("%d ->",i);
            for(int j=0;j<m;j++){
                work[j] += alloc[i][j];
            }
            i = -1;
        }
    }

    for(int i=0;i<n;i++){
        if(!finish[i]) return -1;
    }
    return 1;
}

int reqres(){
    int reqp = 1;
    int req[3] = {1,0,0};

    for(int i=0;i<m;i++){
        if(need[reqp][i]<req[i]){
            printf("Max claim exceeded\n");
            return -1;
        }
        if(avail[i]<req[i]){
            printf("Resource not available\n");
            return -1;
        }
    }
    
    for(int i=0;i<m;i++){
        alloc[reqp][i] += req[i];
        need[reqp][i] -= req[i];
        avail[i] -= req[i];
    }

    if(safety()) {printf("Request granted"); return 1;}
	else {printf("Not possible");return -1;}
}

int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = maxx[i][j]- alloc[i][j];
        }
    }

    printf("\n%d\n",reqres());
}