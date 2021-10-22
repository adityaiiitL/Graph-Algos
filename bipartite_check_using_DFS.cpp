#include<bits/stdc++.h>
using namespace std;

bool dfs(int v,vector<int> adj[],vector<int> &color){

    if(color[v]==-1)color[v]=1;

    for(auto i:adj[v]){
        if(color[i]==-1){
            color[i]=(1^color[v]);

            if(!dfs(i,adj,color)){
                return false;
            }
        }
        else if(color[i]==color[v]){
            return false;
        }
    }
    return true;
}

// Any graph that has an odd-length cycle is never a bipartite
// Any graph that doesnt has an odd-length cycle is always a bipartite graph
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    vector<int>color(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool valid=false;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(dfs(i,adj,color)){
                valid=true;
                break;
            }
        }
    }
    if(valid)cout<<"Bipartite"<<endl;
    else cout<<"No Bipartite"<<endl;
}