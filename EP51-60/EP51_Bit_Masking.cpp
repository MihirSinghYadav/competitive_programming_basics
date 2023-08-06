#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

void print_binary(int n)
{
    cout << bitset<31>(n) << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
    {
        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for (int j = 0; j < num_workers; j++)
        {
            int day;
            cin >> day;
            // masks[i] |= (1 << day);
            mask |= (1 << day);
        }
        masks[i] = mask;
    }
    for (int i = 0; i < n; i++)
    {
        print_binary(masks[i]);
    }
    int maxDays = 0;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int common = masks[i] & masks[j];
            int commonDays = __builtin_popcount(common);
            if (commonDays > maxDays)
            {
                maxDays = commonDays;
                p1 = i;
                p2 = j;
            }
            cout << i << " " << j << " " << commonDays << endl;
        }
    }
    cout << "Max Days Common: " << maxDays << endl;
    cout << "Pair: " << p1 << " " << p2 << endl;
}
/*
Input:
5
4
1 4 7 9
6
2 9 1 7 25 29
7
1 23 4 7 9 11 29
10
2 28 8 7 9 10 30 21 18 19
4
1 11 29 7
*/