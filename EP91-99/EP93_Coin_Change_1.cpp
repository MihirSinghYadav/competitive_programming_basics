#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://leetcode.com/problems/coin-change/

int dp[10010];
int func(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int answer = INT_MAX;
    for (auto coin : coins)
    {
        if (amount - coin >= 0)
            answer = min(answer + 0LL, func(coins, amount - coin) + 1LL);
    }
    return dp[amount] = answer;
}

int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int answer = func(coins, amount);
    return answer == INT_MAX ? -1 : answer;
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    cout << coinChange(coins, amount) << endl;
}
/*
Input
3 11
1 2 5
Output
3
*/