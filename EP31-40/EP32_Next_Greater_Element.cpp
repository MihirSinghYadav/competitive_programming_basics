#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!s.empty() && nums[s.top()] < nums[i % n])
        {
            result[s.top()] = i % n;
            s.pop();
        }
        if (i < n)
            s.push(i);
    }
    return result;
}

int main()
{
    vector<int> nums = {4, 5, 5, 4, 1, 85, 8, 1, 531, 56, 4, 1, 3244, 65, 1, 654, 65, 16, 51, 654, 651};
    vector<int> result = nextGreaterElement(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}