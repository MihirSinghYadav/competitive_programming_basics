#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound(vector<int> &v, int element)
{
    int low = 0, high = v.size() - 1;
    int mid;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (v[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] >= element)
    {
        return low;
    }
    else if (v[high] >= element)
    {
        return high;
    }
    return -1;
}

int upper_bound(vector<int> &v, int element)
{
    int low = 0, high = v.size() - 1;
    int mid;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (v[mid] <= element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] > element)
    {
        return low;
    }
    else if (v[high] > element)
    {
        return high;
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int toFind = 13;
    int lb = lower_bound(v, toFind);
    int ub = upper_bound(v, toFind);
    cout << "Lower Bound: " << lb << " - " << (lb != -1 ? v[lb] : -1)
         << endl;
    cout << "Upper Bound: " << ub << " - " << (ub != -1 ? v[ub] : -1) << endl;
}