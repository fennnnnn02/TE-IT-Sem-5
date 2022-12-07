#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct Process{
    int id,at,bt,tat,wt,ct;
};

void sort_by_at(struct Process p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[i].at>p[i+1].at){
                struct Process temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
            }
        }
    }
}

void print(struct Process p[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].tat,p[i].ct);
    }
}

void SJFP(struct Process p[],int n){
    int completed=0,ct=0;
    
    int rbt[n];
    for(int i=0;i<n;i++){
        rbt[i] = p[i].bt;
    }

    while(completed<n){
        int ind, m=1000000;
        int flag=0;
        for(int i=0;i<n;i++){
            if(rbt[i]>0 && p[i].at<=ct){
                flag=1;
                if(rbt[i]<m){
                    ind = i;
                    m = rbt[i];
                }
            }
        }
        if(flag){
            printf("dsfkd\n");
            rbt[ind]--;
            ct++;
            if(rbt[ind]==0){
                completed++;
                p[ind].tat = ct-p[ind].at;
                p[ind].ct = ct;
                p[ind].wt = p[ind].tat - p[ind].bt;
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(rbt[i]>0){
                    ct = p[i].at;
                    break;
                }
            }
        }
    }
}

int main(){
    int n;
    printf("Enter total processes: ");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        p[i].id = i+1;
        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&p[i].bt);
        printf("Enter arrival time of process %d: ",i+1);
        scanf("%d",&p[i].at);
    }

    sort_by_at(p,n);
    SJFP(p,n);
    print(p,n);
}