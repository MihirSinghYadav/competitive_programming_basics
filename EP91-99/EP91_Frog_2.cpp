#include <iostream>
#include <algorithm>
using namespace std;
// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_b

const int N = 1e5 + 10;
int h[N];
int dp[N];
int func(int n, int k)
{
    // base case
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cost = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        if (n - i - 1 >= 0)
            cost = min(cost, func(n - i - 1, k) + abs(h[n] - h[n - i - 1]));
    }
    return dp[n] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    cout << func(n - 1, k) << endl;
}
/*
Sample Input 1
5 3
10 30 40 50 20
Sample Output 1
30
If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2
3 1
10 20 10
Sample Output 2
20
If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.

Sample Input 3
2 100
10 10
Sample Output 3
0
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input 4
10 4
40 10 20 70 80 10 20 70 80 60
Sample Output 4
40
If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
*/