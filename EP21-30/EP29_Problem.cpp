#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<int, set<string>> marks_map;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int marks;
        cin >> name >> marks;
        marks_map[marks].insert(name);
    }
    cout << "Output:" << endl;
    for (auto it = marks_map.rbegin(); it != marks_map.rend(); it++)
    {
        auto &students = it->second;
        for (auto student : students)
        {
            cout << student << " " << it->first << endl;
        }
    }
}