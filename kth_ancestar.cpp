#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1;
const int maxN=20;

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
int kth_ancestor(int u,int k){

    if(k==0)return u;

    for(int i=0;i<=maxN;i++){
        if(k&(1LL<<i)){
            u=LCA[u][i];
        }
    }
    return u;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int h;
        cin>>h;
        adj[i].push_back(h);
        adj[h].push_back(i);
    }
    init(n);

    while(q--)
    {
        int x,k;
        cin>>x>>k;
        
        int boss=kth_ancestor(x,k);
        if(boss==0)cout<<-1<<endl;
        else cout<<boss<<endl;
    }
}