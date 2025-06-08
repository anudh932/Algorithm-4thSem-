#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edgelist;
vector<int> W;
int n, e;

void b(int src) {
    vector<int> di(n + 1, INT_MAX);
    di[src] = 0;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edgelist[j].first;
            int v = edgelist[j].second;
            int w = W[j];


            if (di[u] != INT_MAX && di[u] + w < di[v]) {
                di[v] = di[u] + w;
            }
        }
    }

    bool hasNegativeCycle = false;
    for(int j = 0; j < e; j++)
    {
        int u = edgelist[j].first;
        int v = edgelist[j].second;
        int w = W[j];

        if(di[u] != INT_MAX && di[u] + w < di[v])
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if(hasNegativeCycle)
        cout << "Yes" << endl;
        else cout<<"no";
}
int main() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back({u, v});
        W.push_back(w);
    }
    b(1);
    return 0;
}
