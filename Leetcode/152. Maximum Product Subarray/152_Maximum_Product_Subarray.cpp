#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        int current_max = 1, current_min = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            int temp = n * current_max;
            current_max = max(temp, max(n * current_min, n));
            current_min = min(temp, min(n * current_min, n));
            result = max(result, current_max);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    int result = s.maxProduct(nums);
    cout << result << endl;
}