#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int bt[n], at[n], wt[n], tat[n], ct[n], pid[n];
    bool done[n] = {false};
    cout<<"Enter the burst time of the processes: "<<endl;
    for(i = 0; i < n; i++) cin>>bt[i], pid[i] = i + 1;
    cout<<"Enter the arrival time of the processes: "<<endl;
    for(i = 0; i < n; i++) cin>>at[i];
    int time = 0, completed = 0;
    while(completed < n)
    {
        int idx = -1, min_bt = INT_MAX;
        for(i = 0; i < n; i++)
            if(!done[i] && at[i] <= time && bt[i] < min_bt)
                min_bt = bt[i], idx = i;
        if(idx == -1) time++;
        else
        {
            ct[idx] = time + bt[idx];
            time = ct[idx];
            done[idx] = true;
            completed++;
        }
    }
    float avg_wt = 0, avg_tat = 0;
    cout<<"\nProcess\tBT\tAT\tWT\tTAT"<<endl;
    for(i = 0; i < n; i++)
    {
        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = ct[i] - at[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        cout<<pid[i]<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<"\nAverage waiting time: "<<avg_wt/n<<endl;
    cout<<"Average turnaround time: "<<avg_tat/n<<endl;
}
