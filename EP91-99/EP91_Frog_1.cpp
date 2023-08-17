#include <iostream>
#include <algorithm>
using namespace std;
// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_a

const int N = 1e5 + 10;
int h[N];
int dp[N];
int func(int n)
{
    // base case
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cost = INT_MAX;
    // way 1
    cost = min(cost, func(n - 1) + abs(h[n] - h[n - 1]));
    // way 2
    if (n > 1)
        cost = min(cost, func(n - 2) + abs(h[n] - h[n - 2]));
    return dp[n] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    cout << func(n - 1) << endl;
}
/*
Sample Input 1
4
10 30 40 20
Sample Output 1
30
If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2
2
10 10
Sample Output 2
0
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.
*/