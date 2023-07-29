#include <iostream>
using namespace std;
int main()
{
    int x = 4;
    int *p = &x;
    cout << "x = " << x << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl
         << endl;

    *p = 5;
    cout << "x = " << x << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl
         << endl;

    int **q = &p;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    cout << "**q = " << **q << endl
         << endl;

    int ***r = &q;
    cout << "r = " << r << endl;
    cout << "*r = " << *r << endl;
    cout << "**r = " << **r << endl;
    cout << "***r = " << ***r << endl;

    return 0;
}