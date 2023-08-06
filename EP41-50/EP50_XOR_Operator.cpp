#include <iostream>
#include <bitset>
using namespace std;

void printBinary(int n)
{
    bitset<11> b(n);
    cout << b << endl;
}
// XOR operator
// 0 0 -> 0
// 0 1 -> 1
// 1 0 -> 1
// 1 1 -> 0
// 5 = 0101
// 3 = 0011
// 5 | 3 = 0111
// 5 & 3 = 0001
// 5 ^ 3 = 0110
// x ^ 0 = x
// x ^ x = 0

int main()
{
    // XOR operator is used to swap 2 numbers
    int a = 4, b = 6;
    a = a ^ b; // a = 2
    b = a ^ b; // b = 4
    a = a ^ b; // a = 6
    cout << a << " " << b << endl;

    // XOR operator is used to find the missing number in an array.
    // Given an array of n-1 integers in the range from 1 to n, find the number that is
    // not repeated in the array.
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int answer = 0;
    for (int i = 0; i < n; i++)
        answer ^= arr[i];
    cout << answer << endl;
}