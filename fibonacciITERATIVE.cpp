
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n){
   int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n;i++){
       dp[i] = dp[i - 1] + dp[i - 2];
    }
  return dp[n];
}

int main(){
    int n;
    cin>>n;
    int result = fibonacci(n);
    cout << result << endl;
    return 0;
}
/*
#include <iostream>
using namespace std;
// Recursive approach
int fibRecursive(int n) {
 if (n <= 1)
 return n;
 return fibRecursive(n-1) + fibRecursive(n-2);*/
