#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int greatest_common_divisor(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a = 15, b = 7;
    cout << greatest_common_divisor(a, b) << endl;
    cout << a * b / greatest_common_divisor(a, b) << endl;
    // cout << __gcd(a, b) << endl;
    cout << std::gcd(a, b) << endl;
}