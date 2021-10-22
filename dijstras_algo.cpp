#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n+1];
    vector<bool>vis(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,1e9);
    int src;
    cin>>src;
    dist[src]=0;
    pq.push({0,src});
    while(pq.size())
    {
        int node=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        for(auto i:adj[node])
        {       
            int next=i.first;
            int nextDist=i.second;
            if(dist[next]>distance+nextDist)
            {
                dist[next]=dist[node]+nextDist;
                pq.push({dist[next],next});
            }   
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]!=1e9)cout<<dist[i]<<' ';
        else cout<<"INF"<<' ';
    }
    return 0;
}