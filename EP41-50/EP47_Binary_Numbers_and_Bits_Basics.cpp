#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    cout << "INT_MAX : " << INT_MAX << endl;
    int a = (1LL << 32) - 1;
    cout << "(1LL<<32)-1 : " << a << endl;
    a = (1LL << 31) - 1;
    cout << "(1LL<<31)-1 : " << a << endl;
    unsigned int b = (1LL << 32) - 1;
    cout << "(1LL<<32)-1 : " << b << endl;
}