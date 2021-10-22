#include<bits/stdc++.h>
using namespace std;

bool dfs(int v,int parent,vector<int> adj[],vector<bool> &visited){

    visited[v]=true;
    for(auto i:adj[v]){
        if(!visited[i]){
            dfs(i,v,adj,visited);
        }
        else if(parent!=i){
            return true;
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
            if(dfs(i,i,adj,visited)){
                valid=true;
                break;
            }
        }
    }
    if(valid)cout<<"Cyclic"<<endl;
    else cout<<"Acyclic"<<endl;
}