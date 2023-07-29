#include <iostream>
using namespace std;

void increment(int n)
{
    n++;
}

int main()
{
    int a = 3;
    cout << a << endl;
    increment(a);
    cout << a << endl;
}