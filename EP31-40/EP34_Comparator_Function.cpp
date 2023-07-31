#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    if (a < b)
        return true;
    return false;
}

bool compare_pair(pair<int, int> a, pair<int, int> b)
{
    if (a > b)
        return true;
    return false;
}

int main()
{

    vector<int> v = {4, 5, 5, 4, 1, 85, 8, 1, 531, 56, 4, 1, 3244, 65, 1, 654, 65, 16, 51, 654, 651};
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(v[i], v[j]))
            {
                swap(v[i], v[j]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<pair<int, int>> v1 = {{1, 2}, {4, 5}, {3, 4}, {5, 7}, {5, 6}};
    int n1 = v1.size();
    for (int i = 0; i < n1; i++)
    {
        for (int j = i + 1; j < n1; j++)
        {
            if (compare_pair(v1[i], v1[j]))
            {
                swap(v1[i], v1[j]);
            }
        }
    }
    cout << "Pair : " << endl;
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i].first << " " << v1[i].second << endl;
}