#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adjL;
vector<bool>vis;

void bfs(int src)
{
    queue<int>q;
    vis[src]=true;
    q.push(src);
    while(!q.empty())
    {
      int current;
      current=q.front();
      q.pop();
      cout<<current<<" ";
    for(auto x:adjL[current])
    {
        if(!vis[x])
        {
            vis[x]=true;
            q.push(x);
        }
    }
    }
}
int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edge: ";
    cin>>n>>e;
    adjL.resize(n+1);
    vis.resize(n+1,false);
    cout<<"Enter the u and v: ";
    for(int i=0;i<e;i++)
    {
      int u,v;
      cin>>u>>v;
      adjL[u].push_back(v);
      adjL[v].push_back(u);
    }
    int src;
    cout<<"enter the src: ";
    cin>>src;
    bfs(src);
    return 0;
}
/*
1 2
1 3
2 4
1 4
3 4
2 5*/
