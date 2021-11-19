#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1;
const int maxN=11;

int LCA[N][maxN];
int level[N];
vector<int> adj[N];
void dfs(int node,int par,int lvl)
{
    level[node]=lvl;
    LCA[node][0]=par;

    for(auto i:adj[node]){
        if(i!=par){
            dfs(i,node,lvl+1);
        }
    }
}
void init(int n){

    dfs(1,-1,0);

    for(int i=1;i<maxN;i++){
        for(int j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1){
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }
    }
}
int getLCA(int u,int v){
    if(level[v]<level[u])swap(u,v);
    int d=level[v]-level[u];

    while(d){
        int i=log2(d);
        v=LCA[v][i];
        d-=(1LL<<i);
    }
    if(u==v)return u;

    for(int i=maxN-1;i>=0;i--){
        if(LCA[u][i]!=-1 and (LCA[u][i]!=LCA[v][i])){
            u=LCA[u][i];
            v=LCA[v][i];
        }
    }
    return LCA[u][0];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(n);

    cout<<getLCA(4,10)<<endl;
}