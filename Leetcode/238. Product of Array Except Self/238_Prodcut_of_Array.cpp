#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> result(len, 1);
        result[0] = 1;
        for (int i = 1; i < len; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int postfix = 1;
        for (int i = len - 1; i > -1; i--)
        {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.productExceptSelf(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
}