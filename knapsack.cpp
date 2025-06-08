#include<bits/stdc++.h>
using namespace std;
int knap(int m,int wi[],int pi[],int n)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 ||j==0)
            {
                dp[i][j]=0;
            }
            else if(wi[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wi[i-1]]+pi[i-1]);
            }
            else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }


int main()
{
int n;
cin>>n;
int wi[n],pi[n];
cout<<"Enter weight and Profit for each item: "<<endl;
for(int i=0;i<n;i++){
cin>>wi[i]>>pi[i];
}
int m;
cout<<"Enter the weight of knapsack: ";
cin>>m;
int maxxProf=knap(m,wi,pi,n);
cout<<maxxProf;

}
