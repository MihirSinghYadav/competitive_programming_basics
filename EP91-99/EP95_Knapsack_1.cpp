#include <iostream>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_d
// KnapSack 1

long knapsack(long long weight[], long long value[], int n, int w)
{
    long long dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
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
/*
Sample Input 1
3 8
3 30
4 50
5 60
Sample Output 1
90
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

Sample Input 2
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Sample Output 2
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 3
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3
17
Items 2,4 and 5 should be taken. Then, the sum of the weights is 5+6+3=14, and the sum of the values is 6+6+5=17.
*/