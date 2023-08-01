#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Arrays : " << endl;
    int a[10] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(int);
    sort(a, a + n);
    int *lb = lower_bound(a, a + n, 4);
    int *ub = upper_bound(a, a + n, 4);
    cout << "Lower Bound : " << *lb << endl;
    cout << "Upper Bound : " << *ub << endl;
    cout << "Occurrence : " << ub - lb << endl;

    cout << "Vectors : " << endl;
    vector<int> v = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    sort(v.begin(), v.end());
    auto lb1 = lower_bound(v.begin(), v.end(), 4);
    auto ub1 = upper_bound(v.begin(), v.end(), 4);
    cout << "Lower Bound : " << *lb1 << endl;
    cout << "Upper Bound : " << *ub1 << endl;
    cout << "Occurrence : " << ub1 - lb1 << endl;

    cout << "Sets : " << endl;
    set<int> s = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    auto lb2 = s.lower_bound(4);
    auto ub2 = s.upper_bound(4);
    cout << "Lower Bound : " << *lb2 << endl;
    cout << "Upper Bound : " << *ub2 << endl;

    cout << "Maps : " << endl;
    map<int, int> m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    auto lb3 = m.lower_bound(4);
    auto ub3 = m.upper_bound(4);
    cout << "Lower Bound : " << lb3->first << " " << lb3->second << endl;
    cout << "Upper Bound : " << ub3->first << " " << ub3->second << endl;
}