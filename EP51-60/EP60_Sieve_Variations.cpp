#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
vector<int> isPrime(N, true);
vector<int> lowestPrime(N, 0), highestPrime(N, 0);
vector<int> divisors[N];

void print_vector(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lowestPrime[i] = highestPrime[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highestPrime[j] = i;
                if (lowestPrime[j] == 0)
                    lowestPrime[j] = i;
            }
        }
    }
    cout << "isPrime: ";
    print_vector(isPrime, 50);
    vector<int> primes = {12, 29, 37, 53, 71, 79, 83, 97};
    for (auto values : primes)
    {
        cout << values << " is " << isPrime[values] << endl;
    }
    cout << "Number Lowest Prime Highest Prime\n";
    for (int i = 40; i <= 50; i++)
    {
        cout << i << "          " << lowestPrime[i] << "          " << highestPrime[i] << endl;
    }
    int num = 840;
    vector<int> prime_factors;
    while (num > 1)
    {
        int prime_factor = highestPrime[num];
        while (num % prime_factor == 0)
        {
            prime_factors.push_back(prime_factor);
            num /= prime_factor;
        }
    }
    cout << "Prime factors of 840 are: ";
    print_vector(prime_factors, prime_factors.size());

    // Divisors
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    for (int i = 1; i < 10; i++)
    {
        for (auto div : divisors[i])
        {
            cout << div << " ";
        }
        cout << endl;
    }
}