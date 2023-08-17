#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://leetcode.com/problems/coin-change-ii/
int dp[310][10010];
int func(vector<int> &coins, int amount, int index)
{
    if (amount == 0)
        return 1;
    if (index < 0)
        return 0;
    if (dp[index][amount] != -1)
        return dp[index][amount];

    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[index])
    {
        ways += func(coins, amount - coin_amount, index - 1);
    }
    return dp[index][amount] = ways;
}

int coinChange2(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    return func(coins, amount, coins.size() - 1);
}

int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0); // Create a DP array with size (amount + 1), initialized to 0
    dp[0] = 1;                     // Base case: There is one way to make an amount of 0, which is by using no coins

    for (int coin : coins)
    { // Iterate through each coin in the given coin set
        for (int j = coin; j <= amount; j++)
        {
            dp[j] += dp[j - coin]; // Update the DP array with possible combinations
        }
    }
    return dp[amount]; // Return the number of combinations to make the given amount
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
    cout << coinChange2(coins, amount) << endl;
    cout << change(amount, coins) << endl;
}
/*
Input
3 5
1 2 5
Output
4
*/