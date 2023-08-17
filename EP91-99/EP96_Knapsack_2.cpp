#include <iostream>
using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_e
// KnapSack 2

long long knapsack(long long weight[], long long value[], int n, int w)
{
    long long dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 100000; j++)
        {
            if (value[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], weight[i - 1] + dp[i - 1][j - value[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 100000; i++)
    {
        if (dp[n][i] <= w)
        {
            ans = i;
        }
    }
    return ans;
} 

int main()
{
    int n, w;
    cin >> n >> w;
    long long weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(weight, value, n, w) << endl;
}