#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<pair<int,int>> adj[],vector<bool> &vis,stack<int> &stk){
    vis[v]=true;
    for(auto i:adj[v]){
        if(!vis[i.first]){
            dfs(i.first,adj,vis,stk);
        }
    }
    stk.push(v);
}
int main(){
    
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n+1];
    vector<bool>vis(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
    }

    stack<int>stk;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,stk);
        }
    }
    
    vector<int>dist(n+1,1e9);
    int src;
    cin>>src;
    dist[src]=0;
    while(stk.size())
    {
        int node=stk.top();
        stk.pop();
        for(auto i:adj[node])
        {
            if(dist[node]+i.second<dist[i.first]){
                dist[i.first]=dist[node]+i.second;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]!=1e9)cout<<dist[i]<<' ';
        else cout<<"INF"<<' ';
    }
    return 0;
}