
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    /*int n;
    cin>>n;
        int num[n];
    for (i=0;i<n;i++)
    {cin>>num[i];
    }
*/
int num[]={7,6,4,3,1};
int n=5;
    vector<int>profit;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if(num[i]<num[j])
            {
            profit[i]=num[j]-num[i];
            }
            else
            {
                profit[i]={0};
            }
        }

    }
    sort(profit.begin(),profit.end());
    cout<<profit[0];
}
