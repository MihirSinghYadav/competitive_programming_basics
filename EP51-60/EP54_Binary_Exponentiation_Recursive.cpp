#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;
const int mod = 1e9 + 7;

int binary_exponentiation_recursive(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binary_exponentiation_recursive(a, b / 2);
    if (b & 1)
    {
        return (a * ((res * res * 1LL) % mod));
    }
    else
    {
        return ((res * res * 1LL) % mod);
    }
}

int main()
{
    cout << pow(2, 3) << endl;
    double d = 1e23;
    cout << fixed << setprecision(30) << d << endl;
    // Do not use float or double for precise values

    int a = 2, b = 13;
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    cout << ans << endl;
    cout << binary_exponentiation_recursive(15, 23) << endl;
}