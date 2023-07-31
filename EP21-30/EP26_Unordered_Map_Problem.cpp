#include <iostream>
#include <unordered_map>
using namespace std;

void print_map(unordered_map<int, string> m)
{
    cout << "Size: " << m.size() << endl;
    for (auto &value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}

int main()
{
    unordered_map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto &value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}
// Input: 8 abc def abc def ghi abc def ghi