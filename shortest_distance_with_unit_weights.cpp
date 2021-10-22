#include<bits/stdc++.h>
using namespace std;

void bfs(int v,vector<int> adj[],int n){

    vector<int>dist(n+1);
    for(int i=1;i<=n;i++)dist[i]=INT_MAX;

    queue<int>q;
    q.push(v);
    dist[v]=0;

    while(q.size()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dist[node]+1<dist[i]){
                q.push(i);
                dist[i]=1+dist[node];
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1,adj,n);
}