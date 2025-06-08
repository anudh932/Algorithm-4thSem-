
#include <bits/stdc++.h>
using namespace std;


int fib(int n){
int dp[n+1]= {-1};
    if (n <= 1){
return n;
}
else {
return fib (n-2)+fib (n-1);}

if(dp[n]!=-1)
    return dp[n];
dp[n]= fib (n-2)+fib (n-1);
return dp[n];
}

    int main(){
    int n = 9;
    int result = fib(n);

    cout << result << endl;

    return 0;
}
