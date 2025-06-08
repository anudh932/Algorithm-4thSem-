#include <bits/stdc++.h>
using namespace std;
void enter(int arr[], int n)
{
  for(int i = 0; i<n; i++)
    cin>>arr[i];
}


void count_activity(int s[], int f[], int n)
{
    vector<pair<int, int>> activities(n);
    for(int i = 0; i < n; i++)
    {
        activities[i] = {f[i], s[i]};
    }
    sort(activities.begin(), activities.end());

    int count = 1;
    int lastFinish = activities[0].first;
    for(int i = 1; i < n; i++) {
        if(activities[i].second >= lastFinish)
        {
            count++;
            lastFinish = activities[i].first;
        }
    }

    cout << count;
}

int main()
{
    int n;
    cin>>n;
    int s[n], f[n];
    enter(s,n);
    enter(f,n);
    count_activity(s, f, n);


    /*
    int s[] = {3, 1, 0, 5, 8, 5};
    int f[] = {4, 2, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    */
}
