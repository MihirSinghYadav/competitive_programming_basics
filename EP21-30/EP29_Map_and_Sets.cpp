#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<pair<int, int>, int> m1;
    pair<int, int> p1, p2;
    p1 = make_pair(1, 2);
    p2 = {2, 3};
    cout << (p1 < p2) << endl;
    map<set<int>, int> m2;
    set<int> s1 = {1, 2, 3};
    set<int> s2 = {2, 3, 4};
    cout << (s1 < s2) << endl;
    map<pair<string, string>, vector<int>> m3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        for (int j = 0; j < ct; j++)
        {
            int x;
            cin >> x;
            m3[{fn, ln}].push_back(x);
        }
    }
    for (auto pr : m3)
    {
        auto &name = pr.first;
        auto &list = pr.second;
        cout << name.first << " " << name.second << endl;
        for (auto &value : list)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}
// Input:3 a b 4 1 2 3 4 c d 2 1 2 d f 3 2 3 4