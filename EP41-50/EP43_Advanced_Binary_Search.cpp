#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
long long m;
long long trees[N];
// https://www.spoj.com/problems/EKO/
bool isWoodEnough(long long height)
{
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] >= height)
        {
            wood += trees[i] - height;
        }
    }
    return wood >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    long long low = 0, high = 1e9, mid;

    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (isWoodEnough(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (isWoodEnough(high))
    {
        cout << high << endl;
    }
    else
    {
        cout << low << endl;
    }
}
// Input: 4 7 20 15 10 17
// Output: 15