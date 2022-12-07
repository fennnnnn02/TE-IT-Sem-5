#include <bits/stdc++.h>

using namespace std;

void bsort(vector<int> &w,vector<int> &v){
    int n = w.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(w[j]>w[j+1]){
                swap(w[j],w[j+1]);
                swap(v[j],v[j+1]);
            }
        }
    }
}

int main(){
    

    int n;
    cout<<"Enter the total number of items: ";
    cin>>n;

    vector<int> weight(n);
    vector<int> value(n);

    for(int i=0;i<n;i++){
        cout<<"Enter weight and value of item "<<i+1<<": ";
        cin>>weight[i]>>value[i];
    }

    int cap; 
    cout<<"Enter capacity: ";cin>>cap;

    bsort(weight,value);

    vector<vector<int>> dp(n+1,vector<int> (cap+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<cap+1;j++){
            if(weight[i-1]<=j) dp[i][j] = max(dp[i-1][j-weight[i-1]]+value[i-1],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<cap+1;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
}