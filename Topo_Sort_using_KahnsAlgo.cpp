#include<bits/stdc++.h>
using namespace std;

void kahn(vector<int> adj[],vector<int> &inDeg,int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(inDeg[i]==0)q.push(i);
    }
    vector<int>topo;
    while(q.size()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:adj[node]){
            inDeg[i]--;
            if(inDeg[i]==0)q.push(i);
        }
    }
    for(auto i:topo)cout<<i<<' ';
}
int main(){

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<bool>vis(n+1);
    vector<int>inDeg(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        inDeg[b]++;
    }
    kahn(adj,inDeg,n);

    return 0;
}