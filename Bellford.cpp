#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edgelist; // To store edges as pairs (u, v)
vector<int> W; // To store weights of edges
int n, e;

void b(int src) {
    vector<int> di(n + 1, INT_MAX); // Distance array
    di[src] = 0; // Distance to source is 0

    // Relax edges up to n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edgelist[j].first;
            int v = edgelist[j].second;
            int w = W[j];

            // Relaxation condition
            if (di[u] != INT_MAX && di[u] + w < di[v]) {
                di[v] = di[u] + w;
            }
        }
    }

    // Output the distances
    for (int i = 1; i <= n; i++) {
        if (di[i] == INT_MAX) {
            cout << "Node " << i << ": unreachable\n";
        } else {
            cout << "Node " << i << ": " << di[i] << "\n";
        }
    }
}

int main() {
    cin >> n >> e; // Read number of nodes and edges
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Read edge (u, v) and weight w
        edgelist.push_back({u, v}); // Add edge to the edge list
        W.push_back(w); // Add weight to the weight list
    }
    b(1); // Call Bellman-Ford from source node 1
    return 0;
}
