#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, cows;
int stalls[N];

bool canPlaceCows(int minimumDistance)
{
    int lastPosition = -1;
    int cowsPlaced = cows;
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastPosition >= minimumDistance)
        {
            lastPosition = stalls[i];
            cowsPlaced--;
        }
        if (cowsPlaced == 0)
            break;
    }
    return cowsPlaced == 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> cows;
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        sort(stalls, stalls + n);
        // TTTTTFFFFFF
        int low = 0, high = 1e9, mid;
        while (high - low > 1)
        {
            int mid = (high + low) / 2;
            if (canPlaceCows(mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (canPlaceCows(high))
        {
            cout << high << endl;
        }
        else
        {
            cout << low << endl;
        }
    }
}
// Input: 1 5 3 1 2 8 4 9
// Output: 3