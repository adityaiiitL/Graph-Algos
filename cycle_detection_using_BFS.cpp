#include<bits/stdc++.h>
using namespace std;

bool bfs(int v,vector<int> adj[],vector<bool> &visited){

    queue<pair<int,int>>q;

    visited[v]=true;
    q.push({v,-1});

    while(q.size()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i]=true;
                q.push({i,node});
            }
            else if(parent!=i){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    vector<bool>visited(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool valid=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(bfs(i,adj,visited)){
                valid=true;
                break;
            }
        }
    }
    if(valid)cout<<"Cyclic"<<endl;
    else cout<<"Acyclic"<<endl;
}