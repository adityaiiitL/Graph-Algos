#include<bits/stdc++.h>
using namespace std;

bool dfs(int v,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis){
    
    vis[v]=true;
    dfsvis[v]=true;
    for(auto i:adj[v]){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsvis))return true;
        }
        else if(dfsvis[i]){
            return true;
        }
    }
    dfsvis[v]=false;
    return false;
}
int main(){

    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    vector<bool>vis(n+1),dfsvis(n+1);

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    bool valid=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsvis)){
                valid=true;
                break;
            }
        }
    }
    if(valid)cout<<"Cyclic"<<endl;
    else cout<<"Acyclic"<<endl;
}