#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of resources: ";
    cin>>m;
    int alloc[n][m], max[n][m], avail[m], need[n][m];
    cout<<"Enter allocation matrix:\n";
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin>>alloc[i][j];
    cout<<"Enter max matrix:\n";
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin>>max[i][j], need[i][j] = max[i][j] - alloc[i][j];
    cout<<"Enter available resources: ";
    for(i = 0; i < m; i++) cin>>avail[i];
    bool finish[n] = {false};
    int safeSeq[n], count = 0;
    while(count < n)
    {
        bool found = false;
        for(i = 0; i < n; i++)
        {
            if(!finish[i])
            {
                bool canAllocate = true;
                for(j = 0; j < m; j++)
                    if(need[i][j] > avail[j])
                        canAllocate = false;
                if(canAllocate)
                {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(!found) break;
    }
    if(count == n)
    {
        cout<<"\nSystem is in safe state.\nSafe sequence: ";
        for(i = 0; i < n; i++)
            cout<<"P"<<safeSeq[i]<<" ";
    }
    else
        cout<<"\nSystem is not in safe state!";
    cout<<endl;
}


