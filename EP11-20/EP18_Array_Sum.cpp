#include <iostream>
using namespace std;

int array_sum(int n, int arr[])
{
    if (n < 0)
    {
        return 0;
    }
    return array_sum(n - 1, arr) + arr[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << array_sum(n, arr);
}