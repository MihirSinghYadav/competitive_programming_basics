#include <iostream>
using namespace std;

void function(int n[])
{
    n[0] = 5;
}

int main()
{
    int a[10] = {0};
    a[0] = 1;
    cout << a[0] << endl;
    function(a);
    cout << a[0] << endl;
}