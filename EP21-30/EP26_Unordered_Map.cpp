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
    unordered_map<int, string> m;
    m[1] = "gbc";
    m[5] = "cdc";
    m[3] = "efg";
    m[2] = "hij";
    m[4] = "klm";
    m.insert({6, "nop"});
    m.insert({7, "qrs"});
    m[8];
    m.erase(4); // O(log(n))
    print_map(m);
    auto it = m.find(3); // O(log(n))
    if (it != m.end())
        cout << "Found: " << it->first << " " << it->second << endl;
    else
        cout << "Not found" << endl;
}