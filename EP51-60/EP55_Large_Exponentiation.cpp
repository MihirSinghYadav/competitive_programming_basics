#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;

const long long int MOD = 1e18 + 7;
int binary_multiplication(long long a, long long b);
long long binary_exponentiation_iterative(long long a, long long b)
{
    long long answer = 1;
    while (b)
    {
        if (b & 1)
        {
            answer = binary_multiplication(answer, a);
        }
        a = binary_multiplication(a, a);
        b >>= 1;
    }
    return answer;
}

// a<=10^18  2^1024
int binary_multiplication(long long a, long long b)
{
    a %= MOD;
    int answer = 0;
    while (b)
    {
        if (b & 1)
        {
            answer = (answer + a) % MOD;
        }
        a = (a + a) % MOD;
        b >>= 1;
    }
    return answer;
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
    cout << binary_multiplication(15, 23) << endl;
}