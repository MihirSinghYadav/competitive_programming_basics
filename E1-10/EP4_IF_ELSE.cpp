#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "Even" << endl;
    }
    else if (n % 3 == 0)
    {
        cout << "Multiple of 3" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
}