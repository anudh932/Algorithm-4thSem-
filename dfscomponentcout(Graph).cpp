#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adjL;
vector<bool>vis;
void dfs(int src)
{
    stack<int>s;
    s.push(src);
    vis[src]=true;
    while(!s.empty())
{
        int current=s.top();
        s.pop();
           cout<<current<<" ";

        for(auto x: adjL[current])
        {
            if(!vis[x])
            {
                vis[x]=true;
                s.push(x);
            }
        }

    }}
int main()
{
    int n,e;
    cout<<"enter the number of nodes and edge: ";
    cin>>n>>e;

    vis.resize(n+1,false);
    adjL.resize(n+1);
    cout<<"Enter U and V: ";
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    //int src;
    //cout<<"enter the source: ";
    //cin>>src;
    //dfs(src);
    int componentCount = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            componentCount++;
        }
    }

    cout << "Number of connected components: " << componentCount << endl;
return 0;
}

