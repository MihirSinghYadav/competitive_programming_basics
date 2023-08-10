#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e7 + 10;
vector<bool> isPrime(N, true);

void print_vector(vector<bool> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Sieve Algorithm
// Time Complexity: O(nloglogn)
// Space Complexity: O(n)

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    print_vector(isPrime, 100);
    vector<int> primes = {12, 29, 37, 53, 71, 79, 83, 97};
    for (auto values : primes)
    {
        cout << values << " is " << isPrime[values] << endl;
    }
}