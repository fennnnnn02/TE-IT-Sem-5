#include<bits/stdc++.h>

using namespace std;

void bf(vector<vector<int>> &g,int src,int V,int e){

    vector<int> dist(V,INT16_MAX);
    dist[src]= 0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<e;j++){
            int u = g[j][0];
            int v = g[j][1];
            int wt = g[j][2];

            if(dist[u]!=INT16_MAX and dist[v]>dist[u]+wt){
                dist[v] = dist[u]+wt;
            }
        }
    }
    for(int j=0;j<e;j++){
            int u = g[j][0];
            int v = g[j][1];
            int wt = g[j][2];

            if(dist[u]!=INT16_MAX and dist[v]>dist[u]+wt){
                cout<<"NEgative"<<endl;
            }
        }

        for(int i=0;i<V;i++){
            cout<<dist[i]<<endl;
        }
}

int main(){
    int n;
    cout<<"Enter total number of vertices: ";
    cin>>n;
    int e;
    cout<<"Enter total number of edges: ";
    cin>>e;
    vector<vector<int>> g(e,vector<int>(3,0));
    for(int i=0;i<e;i++){
        cout<<"Enter vertices of edge "<<i+1<<": ";
        cin>>g[i][0];
        cin>>g[i][1];
        cout<<"Enter weight of edge "<<i+1<<": ";
        cin>>g[i][2];
    }
    int src;
    cout<<"Enter source vertex between 0 and "<<n-1<<endl;
    cin>>src;
    bf(g,src,n,e);
}