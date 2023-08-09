#include <iostream>
#include <vector>
using namespace std;
// Prime Factorization

void print_vector(vector<int> &v)
{
    for (auto value : v)
    {
        cout << value << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        prime_factors.push_back(n);

    print_vector(prime_factors);
}