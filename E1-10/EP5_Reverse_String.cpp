#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string str_reverse;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        str_reverse.push_back(str[i]);
    }
    cout << str_reverse << endl;
    if (str == str_reverse)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}