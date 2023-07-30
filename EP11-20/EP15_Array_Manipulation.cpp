#include <iostream>
using namespace std;
const int N = 1e7 + 10;
long long int arr[N];
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        cout << a << " " << b << " " << k << endl;
        arr[a] += k;
        cout << "arr[a] " << arr[a] << endl;
        if (b + 1 <= n)
        {
            arr[b + 1] -= k;
            cout << "arr[b+1] " << arr[b + 1] << endl;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        cout << "arr[i] " << arr[i] << endl;
    }
    long long int max = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            cout << "max " << max << endl;
        }
    }
    cout << max << endl;
}

// Input: 5 3 1 2 100 2 5 100 3 4 100
// Output: 200
// Input: 4 3 2 3 603 1 1 286 4 4 882
// Output: 882