#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int dp[N];

// Top-down approach
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    // Memoization
    if (dp[n] != -1)
        return dp[n];
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    // Bottom-up approach
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
    cout << fib(n) << endl;
}
// time complexity: O(n) compared to O(2^n) in naive approach