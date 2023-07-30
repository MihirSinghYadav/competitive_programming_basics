#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<pair<int, int>> &v)
{
    cout << "Output:" << endl;
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}

using namespace std;
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
        // v.push_back(make_pair(x, y));
    }

    printVector(v);

    return 0;
}