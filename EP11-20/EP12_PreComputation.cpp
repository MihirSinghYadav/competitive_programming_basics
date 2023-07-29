#include <iostream>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long factorial[N];

int main()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < N; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << factorial[n] << endl;
    }
}