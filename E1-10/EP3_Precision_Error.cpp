#include <iostream>
using namespace std;
int main()
{
    double a = 100000;
    double b = 100000;
    double c = a * b;
    c = 1e24;
    cout << fixed << c << endl;
}