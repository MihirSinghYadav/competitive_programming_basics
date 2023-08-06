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
    // Upper case and lower case conversion
    for (char c = 'A'; c <= 'E'; c++)
    {
        cout << c << " - ";
        printBinary(c);
        cout << " || ";
        cout << (char)(c | ' '); // upper to lower
        cout << " - ";
        printBinary(c | ' ');
        cout << endl;
    }

    char A = 'A';
    char a = A | (1 << 5);
    cout << a << endl;
    cout << (char)(a & (~(1 << 5))) << endl;          // lower to upper
    cout << "____" << char(1 << 5) << "____" << endl; // 32 - space
    cout << char('c' & '_') << endl;                  // lower to upper
}