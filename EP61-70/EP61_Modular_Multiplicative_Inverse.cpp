#include <iostream>
using namespace std;
const int M = 1e9 + 7;

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

const int N = 1e6 + 10;
int factorial[N];
int main()
{
    cout << binary_exponentiation(2, M - 2, M) << endl;

    // This is the modular multiplicative inverse of 2 modulo M
    // This is the same as 2^(M-2) modulo M
    ///////////////////////////////////////////////////////////////////
    // There are N children and K candies.
    //  Each child should get the same number of candies.
    //  K<N
    //  How many ways are there to distribute the candies?
    //  nCk = n! / (k! * (n-k)!)
    // M = 10^9 + 7
    // N<10^6, K<N<10^6
    // Q queries, Q<10^5
    factorial[0] = 1;
    for (int i = 1; i < N; i++)
    {
        factorial[i] = (factorial[i - 1] * 1LL * i) % M;
    }
    int q, answer;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int numerator = factorial[n];
        int denominator = (factorial[k] * 1LL * factorial[n - k]) % M;
        answer = (numerator * 1LL * binary_exponentiation(denominator, M - 2, M)) % M;
    }
    cout << answer << endl;
}