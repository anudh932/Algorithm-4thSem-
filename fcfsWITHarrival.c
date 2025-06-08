#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int bt[n], at[n], wt[n], tat[n], ct[n], pid[n];
    cout<<"Enter the burst time of the processes: "<<endl;
    for(i = 0; i < n; i++) cin>>bt[i], pid[i] = i + 1;
// Set arrival time to 0 if arrival time is not mentioned
    cout<<"Enter the arrival time of the processes: "<<endl;
    for(i = 0; i < n; i++) cin>>at[i];
    for(i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(at[j] > at[j+1])
                swap(at[j], at[j+1]), swap(bt[j], bt[j+1]), swap(pid[j],
                        pid[j+1]);
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++)
        ct[i] = max(ct[i-1], at[i]) + bt[i];
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
