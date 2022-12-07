#include<bits/stdc++.h>

using namespace std;

#define N 5
#define INF INT_MAX

struct Node{
    vector<pair<int,int>> path;
    int redMatrix[N][N];
    int cost;
    int level;
    int vertex;
};

Node* newNode(int parent[N][N],vector<pair<int,int>> const &path,int i,int j,int level){

    Node* node = new Node;

    node->path = path;

    if(level!=0) node->path.push_back(make_pair(i,j));

    memcpy(node->redMatrix,parent,sizeof node->redMatrix);

    for(int k=0;k<N and level!=0;k++){
        node->redMatrix[i][k] = INF;
        node->redMatrix[k][j] = INF;
    }

    node->redMatrix[j][0] = INF;

    node->vertex = j;
    node->level = level;
    return node;

}

int rr(int redMatrix[N][N],int row[N]){
    fill_n(row,N,INF);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(row[i]>redMatrix[i][j]){
                row[i] = redMatrix[i][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(row[i]!=INF and redMatrix[i][j]!=INF){
                redMatrix[i][j]-=row[i];
            }
        }
    }
}

int cr(int redMatrix[N][N],int row[N]){
    fill_n(row,N,INF);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(row[j]>redMatrix[i][j]){
                row[j] = redMatrix[i][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(row[j]!=INF and redMatrix[i][j]!=INF){
                redMatrix[i][j]-=row[j];
            }
        }
    }
}

int calcost(int redMatrix[N][N]){
    int cost =0;

    int row[N];
    rr(redMatrix,row);

    int col[N];
    cr(redMatrix,col);

    for(int i=0;i<N;i++){
        cost+= (row[i]!=INF) ? row[i]:0;
        cost+= (col[i]!=INF) ? col[i]:0;
    }
    return cost;
}

void printpath(vector<pair<int,int>> const &path){
    for(int i=0;i<path.size();i++){
        cout<<path[i].first+1<<"->"<<path[i].second+1<<endl;
    }
}

struct comp{
    bool operator()(const Node* lhs,const Node* rhs)const{
        return lhs->cost>rhs->cost;
}
};

int solve(int costMatrix[N][N]){
    priority_queue<Node*,vector<Node*>,comp> pq;

    vector<pair<int,int>> v;

    Node* root = newNode(costMatrix,v,-1,0,0);

    root->cost = calcost(root->redMatrix);

    pq.push(root);

    while(!pq.empty()){
        Node *min = pq.top();
        pq.pop();
        int i = min->vertex;
        if(min->level==N-1){
            min->path.push_back(make_pair(i,0));
            printpath(min->path);
            return min->cost;
        }

        for(int j=0;j<N;j++){
            if(min->redMatrix[i][j]!=INF){
                Node * node = newNode(min->redMatrix,min->path,i,j,min->level+1);
                node->cost = min->cost + min->redMatrix[i][j]+ calcost(node->redMatrix);
                pq.push(node);
            }
        }
        delete min;
    }


}

int main(){
    int costMatrix[N][N] =
    {
        { INF, 10, 8, 9, 7 },
        { 10, INF, 10, 5, 6 },
        { 8, 10, INF, 8, 9 },
        { 9, 5, 8, INF, 6 },
        { 7, 6, 9, 6, INF }
    };

    cout << "\n\nTotal cost is " << solve(costMatrix);
}