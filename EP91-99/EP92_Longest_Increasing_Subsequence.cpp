#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://leetcode.com/problems/longest-increasing-subsequence/
vector<int> nums;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
// dynamic programming
// time complexity: O(n^2)

int lis(int n)
{
    int answer = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[n] > nums[i])
        {
            answer = max(answer, 1 + lis(i));
        }
    }
    return answer;
}
// recursive
// time complexity: O(2^n)

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < lis(i))
            max = lis(i);
    cout << max << endl;
    cout << lengthOfLIS(nums) << endl;
}
/*
Input
8
10
9
2
5
3
7
101
18
Output
4
*/