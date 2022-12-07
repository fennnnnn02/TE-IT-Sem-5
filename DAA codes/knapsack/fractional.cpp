#include <bits/stdc++.h>

using namespace std;

struct Item{
    int weight;
    int value;
    float ratio;
};

bool comp(Item i1,Item i2){
    return i1.ratio>i2.ratio;
}

int main(){
    int n;
    cout<<"Enter total no. of items: ";
    cin>>n;

    Item item[n];
    for(int i=0;i<n;i++){
        cout<<"Enter weight of item "<<i+1<<": ";
        cin>>item[i].weight;
        cout<<"Enter value of item "<<i+1<<": ";
        cin>>item[i].value;

        item[i].ratio = item[i].value/item[i].weight;
    }

    int cap;
    cout<<"Enter capacity of knapsack: ";
    cin>>cap;

    sort(item,item+n,comp);

    int curr = cap;
    int j=0; float maxprofit=0;

    while(curr>0){
        if(item[j].weight<=curr){
            curr = curr - item[j].weight;
            maxprofit = maxprofit+item[j].value;
            j++;
        }
        else{
            maxprofit += (float)curr/item[j].weight*item[j].value;
            break;
        }
    }

    cout<<maxprofit<<endl;
}