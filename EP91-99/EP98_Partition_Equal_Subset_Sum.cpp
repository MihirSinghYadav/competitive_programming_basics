#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
// https://leetcode.com/problems/partition-equal-subset-sum/

int dp[205][20005];
int func(int n, int sum, vector<int> &nums)
{
    if (sum == 0)
        return 1;
    if (n < 0 || sum < 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    return dp[n][sum] = func(n - 1, sum - nums[n], nums) || func(n - 1, sum, nums);
}

bool canPartition(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum /= 2;
    return func(nums.size() - 1, sum, nums);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << canPartition(nums) << endl;
}
/*
Input
4
1 5 11 5
Output
1
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Input 2
4
1 2 3 5
Output 2
0
Explanation: The array cannot be partitioned into equal sum subsets.
*/