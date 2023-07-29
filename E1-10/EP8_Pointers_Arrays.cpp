#include <iostream>
using namespace std;
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = a;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << "&a[0] = " << &a[0] << endl;
}