#include <iostream>
#include <bitset>
using namespace std;

void printBinary(int n)
{
    bitset<11> b(n);
    cout << b << endl;
}

int main()
{
    // Clear LSB
    cout << "     ";
    printBinary(59);
    int a = 59;
    int i = 4;
    int lsb = (a & (~((1 << (i + 1)) - 1)));
    cout << "lsb: ";
    printBinary(lsb);

    // Clear MSB
    i = 3;
    int msb = (a & ((1 << (i + 1)) - 1));
    cout << "msb: ";
    printBinary(msb);

    // Power of 2
    int n = 15;
    if ((n & (n - 1)) == 0)
        cout << "Power of 2" << endl;
    else
        cout << "Not power of 2" << endl;
}