#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());

    int count = 1;
    int lastFinish = v[0].second;

      for(int i = 1; i < n; i++) {
        if(v[i].second >= lastFinish)
        {
            count++;
            lastFinish = v[i].first;
        }
    }

    cout << count;
}
