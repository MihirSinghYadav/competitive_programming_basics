#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int toFind;
    cin >> toFind;
    int low = 0, high = n - 1;
    int mid;
    while (high - low > 1)
    {
        mid = (low + high) / 2;
        if (v[mid] < toFind)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] == toFind)
    {
        cout << low;
    }
    else if (v[high] == toFind)
    {
        cout << high;
    }
    else
    {
        cout << "Not Found";
    }
}