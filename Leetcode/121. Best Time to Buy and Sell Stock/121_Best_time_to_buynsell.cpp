#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0, right = 1;
        int max_profit = 0;
        while (right < prices.size())
        {
            if (prices[left] < prices[right])
            {
                max_profit = max(max_profit, prices[right] - prices[left]);
            }
            else
            {
                left = right;
            }
            right++;
        }
        return max_profit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}