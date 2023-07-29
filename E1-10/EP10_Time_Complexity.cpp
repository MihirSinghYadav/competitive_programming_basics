#include <iostream>
using namespace std;
int main()
{
    // O(1)
    int a = 2;
    cout << a << endl;
    // O(N)
    for (int i = 0; i < a; i++)
    {
        cout << i << endl;
    }
    // O(N*N)
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << i << " " << j << endl;
        }
    }
    // O(NlogN)
    for (int i = 0; i < a; i++)
    {
        for (int j = 1; j < a; j *= 2)
        {
            cout << i << " " << j << endl;
        }
    }
    // O(N*N*N)
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < a; k++)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
    // O(N*N*N*N)
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < a; k++)
            {
                for (int l = 0; l < a; l++)
                {
                    cout << i << " " << j << " " << k << " " << l << endl;
                }
            }
        }
    }
}