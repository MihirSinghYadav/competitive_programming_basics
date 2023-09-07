#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int result = nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (nums.at(left) < nums.at(right))
            {
                result = min(result, nums.at(left));
                break;
            }
            int mid = (left + right) / 2;
            result = min(result, nums.at(mid));
            if (nums.at(left) <= nums.at(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution s;
    int result = s.findMin(nums);
    cout << result << endl;
}