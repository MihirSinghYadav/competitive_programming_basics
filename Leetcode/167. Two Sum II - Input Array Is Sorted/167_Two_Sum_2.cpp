#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int first = 0;
        int last = numbers.size() - 1;

        while (first < last)
        {
            int sum = numbers[first] + numbers[last];
            if (sum == target)
                return {first + 1, last + 1};
            else if (sum < target)
                first++;
            else if (sum > target)
                last--;
        }
        return {};
    }
};
int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    auto result = s.twoSum(numbers, target);
    for (int n : result)
        cout << n << " ";
}