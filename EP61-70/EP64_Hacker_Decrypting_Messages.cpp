#include <iostream>
#include <vector>
using namespace std;
const int N = 2e6 + 10;
int a[N];
int hp[N];
int canRemove[N]; // canRemove[i] -> if i can be removed 1, else 0
int hsh[N];
vector<int> distinct_prime_factors(int x)
{
    vector<int> answer;
    while (x > 1)
    {
        int p = hp[x];
        while (x % p == 0)
            x /= p;
        answer.push_back(p);
    }
    return answer;
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x] = 1;
    }
    for (int i = 2; i < N; i++)
    {
        if (hsh[i])
        {
            for (long long j = i; j < N; j *= i)
            {
                canRemove[j] = 1;
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pf = distinct_prime_factors(x);
        bool isPossible = false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];
                if (i == j && x % product != 0)
                    continue;
                int toRemove = x / product;
                if (canRemove[toRemove] == 1 || toRemove == 1)
                {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible)
                break;
        }
        cout << (isPossible ? "YES\n" : "NO\n");
    }
}