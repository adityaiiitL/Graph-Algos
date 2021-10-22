#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=1;i<=m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    vector<int>parent(n+1,-1),key(n+1,INT_MAX);
    vector<bool>mstSet(n+1,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[1]=0;
    parent[1]=-1;
    pq.push({0,1});
    for(int i=1;i<=n-1;i++){

        /* brute force (N^2)
        int mn=INT_MAX,node;
        for(int v=1;v<=n;v++){
            if(mstSet[v]==false and key[v]<mn){
                mn=key[v];
                node=v;
            }
        }
        */
        int node=pq.top().second;
        pq.pop();
        mstSet[node]=true;
        for(auto it:adj[node]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false and weight<key[v]){
                parent[v]=node;
                key[v]=weight;
                pq.push({key[v],v});
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }
}