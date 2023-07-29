#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    cout << ((b > a) && (b > c)) << endl;
    cout << ((b > a) || (b > c)) << endl;
    return 0;
}