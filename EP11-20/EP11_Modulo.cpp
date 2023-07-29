#include <iostream>
using namespace std;

/*
Modulo is the remainder of a division operation.
In C++, the modulo operator is %.
(a+b)%M = ((a%M) + (b%M))%M
(a*b)%M = ((a%M) * (b%M))%M
(a-b)%M = ((a%M) - (b%M) + M)%M
(a/b)%M = ((a%M) * (b^-1%M))%M

*/

int main()
{
    int n;
    cin >> n;
    int M = 47;
    long long factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial = (factorial * i) % M;
    }
    cout << factorial << endl;
}