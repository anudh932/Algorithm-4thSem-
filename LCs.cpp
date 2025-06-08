#include<bits/stdc++.h>
using namespace std;
int lcs(string t1, string t2)
{
 int n = t1.length(), m = t2.length();
 vector<vector<int>> dp (n+1, vector<int>(m+1, 0));
 for(int i = 0; i <= n; i++)
 {
 for(int j = 0; j <= m; j++)
 {
 if(i==0 || j==0)
 cout<<"0 ";
 else if(t1[i-1] == t2[j-1])
 {
 dp[i][j] = dp[i-1][j-1] + 1;
 cout<<dp[i][j]<<" ";
 }
else
 {
 dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
 }
 }
 /*cout<<dp[i][j]<<" ";
 }
 }
 cout<<endl;
 }*/
 return dp[n][m];
}
int main()
{
 string t1,t2;
 cin>>t1;
 cin>>t2;
 cout<<lcs(t1,t2);
}
