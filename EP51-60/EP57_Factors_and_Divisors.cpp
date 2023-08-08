#include <iostream>
using namespace std;

// Sum of Divisors of a number
// n = (p1^a1 + p1^a1 + ... + pn^an) where n = p1^a1 * p2^a2 * ... * pn^an
// Sum of divisors = (p1^0 + p1^1 + ... + p1^a1) * (p2^0 + p2^1 + ... + p2^a2) * ... * (pn^0 + pn^1 + ... + pn^an)
// Sum of divisors = (p1^(a1+1) - 1) / (p1 - 1) * (p2^(a2+1) - 1) / (p2 - 1) * ... * (pn^(an+1) - 1) / (pn - 1)
//

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int sum = 0;
    cout << "Factors of " << n << " are: " << endl;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " - " << n / i << endl;
            count++;
            sum += i;
            if (n / i != i)
            {
                sum += n / i;
                count++;
            }
        }
    }
    cout << "Number of factors: " << count << endl;
    cout << "Sum of factors: " << sum << endl;
}