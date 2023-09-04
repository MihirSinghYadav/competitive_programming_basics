#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
    // time complexity: O(n^2)
};

class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (umap.find(diff) != umap.end())
                return {umap[diff], i};
            umap[nums[i]] = i; // key = nums[i], value = i
        }
        return {0, 0};
    }
    // time complexity: O(n)
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    Solution2 sol2;
    vector<int> ans2 = sol2.twoSum(nums, target);
    cout << ans2[0] << " " << ans2[1] << endl;
    return 0;
}