#include <iostream>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int factorial[N];

int binary_exponentiation(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    factorial[0] = 1;
    for (int i = 1; i < N; i++)
    {
        factorial[i] = (factorial[i - 1] * 1LL * i) % M;
    }
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int answer = factorial[n];
        answer = (answer * 1LL * factorial[k]) % M;
        int denominator = (factorial[k - n] * 1LL * factorial[n]) % M;
        answer = (answer * 1LL * binary_exponentiation(denominator, M - 2, M)) % M;
        cout << answer << endl;
    }
}