#include <iostream>
using namespace std;

void function(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    function(n - 1);
    cout << n << endl;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    for (int i = 0; i <= n; i++)
        return factorial(n - 1) * n;
}

int main()
{
    function(5);
    cout << factorial(5) << endl;
}