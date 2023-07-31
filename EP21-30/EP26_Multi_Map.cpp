#include <iostream>
#include <unordered_map>
using namespace std;

void print_map(unordered_multimap<int, string> m)
{
    cout << "Size: " << m.size() << endl;
    for (auto &value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
}

int main()
{
    unordered_multimap<int, string> m;
    m.insert({1, "abc"});
    m.insert({5, "def"});
    m.insert({3, "abc"});
    m.insert({2, "def"});
    m.insert({4, "ghi"});
    m.insert({6, "abc"});
    m.insert({2, "def"});
    m.erase(4); // O(log(n))
    print_map(m);
    auto it = m.find(3); // O(log(n))
    if (it != m.end())
        cout << "Found: " << it->first << " " << it->second << endl;
    else
        cout << "Not found" << endl;
}