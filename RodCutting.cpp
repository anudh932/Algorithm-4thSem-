#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCutting(const int prices[], int n) {
    // Create a vector to store the maximum revenue for each i
    //vector<int> dp(n + 1, 0);
    int dp[n+1]={0};

    // Build the dp array in a bottom-up manner
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= i;j++) {
            if (j <= n) { // Ensure the j does not exceed the prices array
                dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
            }
        }
    }

    return dp[n];
}

int main() {
    // Prices for lengths 1 to n
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20}; // Example prices for lengths 1 to 8
    int n;
    cin>>n; // i of the rod
    int maxProfit = rodCutting(prices, n);
    cout << "The maximum obtainable revenue for a rod of i " << n << " is: " << maxProfit << endl;

    return 0;
}
