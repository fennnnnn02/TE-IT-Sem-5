#include<bits/stdc++.h>

using namespace std;

int ld[30]={0},rd[30]={0},r[30]={0};

bool solve(vector<vector<int>> &b,int col,int n){
    if(col==n) return true;
    else{
        for(int i=0;i<n;i++){
            if(ld[i-col+n-1]==0 and rd[i+col]==0 and r[i]==0){
                b[i][col] = 1;
                ld[i-col+n-1] =1;
                r[i] = 1;
                rd[i+col] = 1;
                if(solve(b,col+1,n)) return true;
                b[i][col] = 0;
                ld[i-col+n-1] =0;
                r[i] = 0;
                rd[i+col] = 0;
            }
        }
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> b(n,vector<int>(n,0));

    solve(b,0,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
}