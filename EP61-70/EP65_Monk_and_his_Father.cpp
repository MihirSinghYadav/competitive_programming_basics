#include <iostream>
using namespace std;
// https://www.hackerearth.com/problem/algorithm/monk-and-his-father-93b639f4/
// Monk and his father
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        cout << __builtin_popcountll(x) << endl;
    }
}