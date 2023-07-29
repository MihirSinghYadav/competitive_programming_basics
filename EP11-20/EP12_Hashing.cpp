#include <iostream>
using namespace std;
const int N = 1e7 + 10;
int hashTable[N];
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hashTable[a[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << hashTable[x] << endl;
    }
}
// Input: 6 3 5 5 7 7 8 3 5 7 8