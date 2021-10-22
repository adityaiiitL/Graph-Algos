#include<bits/stdc++.h>
using namespace std;

class DSU
{
public:
    DSU(vector<int> &parent,vector<int> &sz,int n){
        for(int i=1;i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
    }
    int find_parent(int v,vector<int> &parent){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find_parent(parent[v],parent);
    }
    void union_set(int a,int b,vector<int> &parent,vector<int> &sz){
        a=find_parent(a,parent);
        b=find_parent(b,parent);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>parent(n+1),sz(n+1);
    DSU dsu(parent,sz,n);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        dsu.union_set(a,b,parent,sz);
    }

    for(int i=1;i<=n;i++){
        cout<<dsu.find_parent(i,parent)<<' ';
    }
    return 0;
}