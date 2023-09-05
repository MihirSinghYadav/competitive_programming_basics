#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            current = max(current + nums[i], nums[i]);
            result = max(current, result);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int result = s.maxSubArray(nums);
    cout << result << endl;
}