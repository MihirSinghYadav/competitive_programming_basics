#include <iostream>
#include <algorithm>
using namespace std;
// Hacker earth Problem: Monk and Divisor Conundrum
// Sieve Algorithm
const int N = 2e5 + 10;
int multiples_count[N];
int hsh[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            multiples_count[i] += hsh[j];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        long long lcm = p * 1LL * q / __gcd(p, q);
        long answer = multiples_count[p] + multiples_count[q];
        if (lcm < N)
        {
            answer -= multiples_count[lcm];
        }
        cout << answer << endl;
    }
    return 0;
}