#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> subsetsAll;
void generate(vector<int> &subset, int i, vector<int> &nums)
{
    if (i == nums.size())
    {
        subsetsAll.push_back(subset);
        return;
    }
    generate(subset, i + 1, nums);

    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> empty;
    generate(empty, 0, nums);
    return subsetsAll;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (auto subset : subsets(nums))
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}