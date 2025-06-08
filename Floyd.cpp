#include <bits/stdc++.h>
using namespace std;

int adjm[100][100];
int V, E;

void floyd() {
    for (int k = 1; k <= V; k++) {
     for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++)
        {if (adjm[i][k] != INT_MAX && adjm[k][j] != INT_MAX) {
                    adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) {
                adjm[i][j] = 0;
            } else {
                adjm[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjm[u][v] = min(adjm[u][v], w);
    }

    floyd();

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (adjm[i][j] == INT_MAX) {
                cout << "Infinity";
            } else {
                cout << adjm[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
/*
4
7
1 2 3
1 4 7
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2
*/
