#include <iostream>
using namespace std;
void increment(int *n)
{
    (*n)++;
    *n = *n + 5;
}

int main()
{
    int a = 5;
    cout << a << endl;
    increment(&a);
    cout << a << endl;
}