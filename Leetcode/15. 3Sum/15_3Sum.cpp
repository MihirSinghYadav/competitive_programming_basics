#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ans.push_back({nums[i], nums[j], nums[k]});
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = sol.threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}