#include<bits/stdc++.h>
using namespace std;

typedef pair <int,int>pii;
vector<pair<int,int> >adjl[100];
int V,E;

int prims()
{int mst;
vector<int>vis(V+1,0);
priority_queue<pii, vector<pii>,greater<pii> >pq;
vis[1]=1;
for(auto p: adjl[1])
{
    pq.push(p);
}

while(!pq.empty())
{
    int w = pq.top().first;
    int n=pq.top().second;

    pq.pop();

    if(vis[n]) continue;

    vis[n]=1;
    mst+=w;

    for(pii q:adjl[n])
    {
        if(vis[q.second]==0)
        {
            pq.push(q);
        }
    }
}
return mst;
}

int main()
{
    cin>> V>>E;

    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjl[u].push_back({w, v});
        adjl[v].push_back({w, u});
    }
    int result = prims();
    cout << "Minimum Spanning Tree Weight: " << result << endl;
    return 0;
}
/*
7
9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/
