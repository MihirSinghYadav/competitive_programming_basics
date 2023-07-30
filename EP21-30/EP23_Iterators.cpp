#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<pair<int, int>> vp = {{1, 2}, {2, 3}, {3, 4}};
    vector<pair<int, int>>::iterator it1;
    for (it1 = vp.begin(); it1 != vp.end(); it1++)
    {
        cout << (*it1).first << " " << (*it1).second << endl;
        cout << it1->first << " " << it1->second << endl;
    }
    return 0;
}