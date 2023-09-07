#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<int> res = sol.countBits(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}