#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,wt;
    node(int x,int y,int weight){
        u=x;
        v=y;
        wt=weight;
    }
};

bool op(node n1,node n2){
    return n1.wt < n2.wt;
}

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

int main(){

    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        edges.push_back(node(x,y,wt));
    }
    sort(edges.begin(),edges.end(),op);

    vector<int> parent(n+1),sz(n+1);
    DSU dsu(parent,sz,n);

    int total_cost=0;
    vector<pair<int,int>>mstSet;
    for(auto i:edges)
    {
        if(dsu.find_parent(i.u,parent)!=dsu.find_parent(i.v,parent))
        {
            mstSet.push_back({i.u,i.v});
            total_cost+=i.wt;
            dsu.union_set(i.u,i.v,parent,sz);
        }

    }
    cout<<total_cost<<endl;
    for(auto i:mstSet){
        cout<<i.first<<" - "<<i.second<<endl;
    }

    return 0;
}