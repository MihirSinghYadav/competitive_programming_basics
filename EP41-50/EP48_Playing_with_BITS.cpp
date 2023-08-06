#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

// 1. Bitwise AND
// 2. Bitwise OR
// 3. Bitwise XOR
// 4. Bitwise NOT
// 5. Bitwise Left Shift
// 6. Bitwise Right Shift
// Binary representation is done using 32 bits, from right to left, starting from 0.
// 0th bit is the rightmost bit, and 31st bit is the leftmost bit.
// 0th bit is the least significant bit (LSB).
// 31st bit is the most significant bit (MSB).
// set bit: 1
// unset bit: 0
// For example: 10111011 is a binary representation of 187.
// It has set bit at 0th, 1st, 3rd, 4th, 5th, and 7th position.
// It has unset bit at 2nd, 6th, and 8th position.
// It has 6 set bits and 3 unset bits.

void printBinary(int n)
{
    bitset<32> b(n);
    cout << b << endl;
}

int main()
{
    printBinary(9);
    int a = 9;
    int i = 1;

    while (a > 0)
    {
        int last_bit = a & 1;
        cout << last_bit << " - ";
        a = a >> 1;
        if (a & (1 << i))
        {
            cout << "Setbit" << endl;
        }
        else
        {
            cout << "UnsetBit" << endl;
        }
    }
    int b = 9;
    cout << "Set bit : ";
    // set bit
    printBinary(b | (1 << 1));
    cout << endl;
    cout << "Unset bit : ";
    // unset bit
    printBinary(9);
    cout << "            ";
    printBinary(~(1 << 3));
    cout << "            ";
    printBinary(b & ~(1 << 3));
    cout << endl;

    // toggle bit
    cout << "Toggle bit : ";
    printBinary(9 ^ (1 << 2));
    cout << "             ";
    printBinary(9 ^ (1 << 3));

    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((15 & (1 << i)) != 0)
        {
            count++;
        }
    }
    cout << "Bits set : " << count << endl;
    cout << "Bits set function : " << __builtin_popcountll(31LL << 35) << endl;
}