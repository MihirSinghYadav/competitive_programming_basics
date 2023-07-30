#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // vector<int>::iterator it;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<pair<int, int>> vp = {{1, 2}, {2, 3}, {3, 4}};
    vector<pair<int, int>>::iterator it1;
    // for (pair<int, int> &value : vp)
    for (auto &value : vp)
    {
        cout << value.first << " " << value.second << endl;
    }
    auto a = 1.0;
    cout << typeid(a).name() << endl;
    cout << typeid(vp).name() << endl;
    return 0;
}