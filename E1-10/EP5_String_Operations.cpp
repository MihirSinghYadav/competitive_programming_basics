#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + " " + str2;
    cout << str3 << endl;
    if (str1 == str2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    str1[0] = 'h';
    cout << str1 << endl;
    cout << str1.length() << endl;
    cout << str1.size() << endl;
}
