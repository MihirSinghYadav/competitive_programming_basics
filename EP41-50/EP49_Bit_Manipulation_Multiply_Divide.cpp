#include <iostream>
#include <bitset>
using namespace std;

void printBinary(int n)
{
    bitset<10> b(n);
    cout << b;
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        printBinary(i);
        cout << " - ";
        if (i & 1)
            cout << "Odd" << endl;
        else
            cout << "Even" << endl;
    }
    int n = 5;
    cout << (n >> 1) << endl; // divide by 2
    cout << (n << 1) << endl; // multiply by 2
}