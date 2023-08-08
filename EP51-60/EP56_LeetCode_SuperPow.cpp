#include <iostream>
#include <vector>

using namespace std;

const int base = 1337;
int binary_exponentiation(int a, int b)
{
    a %= base;
    int answer = 1;
    for (int i = 0; i < b; i++)
    {
        answer = (answer * a) % base;
    }
    return answer;
}
int superPow(int a, vector<int> &b)
{
    if (b.empty())
        return 1;
    int lastDigit = b.back();
    b.pop_back();
    return binary_exponentiation(superPow(a, b), 10) * binary_exponentiation(a, lastDigit) % base;
}
int main()
{
    int a;
    vector<int> b;
    cout << "Enter a: ";
    cin >> a;

    int bLength;
    cout << "Enter the length of b: ";
    cin >> bLength;

    cout << "Enter " << bLength << " elements for b: ";
    for (int i = 0; i < bLength; ++i)
    {
        int value;
        cin >> value;
        b.push_back(value);
    }

    int result = superPow(a, b);
    cout << "Result: " << result << endl;

    return 0;
}