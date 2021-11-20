#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1;
const int maxN=11;

int LCA[N][maxN],res[N][maxN];
int level[N],val[N];
vector<int> adj[N];
void dfs(int node,int par,int lvl)
{
    level[node]=lvl;
    LCA[node][0]=par;

    if(par==-1)res[node][0]=0;
    else res[node][0]=val[par];

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
            if(LCA[j][i-1]!=-1)
            {
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
                res[j][i]=res[par][i-1]+res[j][i-1];
            }
            else {
                res[j][i]=res[j][i-1];
            }
        }
    }
}
int kth_result(int x,int k){
    int ans=val[x];
    if(k==0)return ans;
    
    for(int i=0;i<maxN;i++){
        if(k&(1LL<<i)){
            ans+=res[x][i];
            x=LCA[x][i];
        }
        if(x==-1)return ans;
    }
    return ans;
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
    for(int i=1;i<=n;i++)cin>>val[i];

    init(n);

    int Q;
    cin>>Q;
    while(Q--)
    {
        int x,k;
        cin>>x>>k;
        cout<<kth_result(x,k)<<endl;
    }
    return 0;
}