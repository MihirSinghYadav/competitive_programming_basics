#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subsetCount = (1 << n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subsetCount; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    // O(n * 2^n)
    return subsets;
}

int main()
{
    // Input: 3 1 2 3
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    auto subset = subsets(v);
    for (auto value : subset)
    {
        for (auto i : value)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}