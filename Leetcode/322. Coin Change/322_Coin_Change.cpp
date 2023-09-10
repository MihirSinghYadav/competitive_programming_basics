#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int c = 0; c < coins.size(); c++)
            {
                if (i - coins[c] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[c]] + 1);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    Solution s;
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
}