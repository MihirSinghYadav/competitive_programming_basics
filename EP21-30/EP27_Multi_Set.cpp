#include <iostream>
#include <unordered_set>
using namespace std;

void print_unordered_multiset(unordered_multiset<string> s)
{
    cout << "Size: " << s.size() << endl;
    for (auto &value : s)
    {
        cout << value << endl;
    }
}

int main()
{
    unordered_multiset<string> s;
    s.insert("abc");
    s.insert("def");
    s.insert("abc");
    s.insert("def");
    s.insert("ghi");
    s.insert("abc");
    s.insert("jkl");
    s.erase("ghi"); // O(log(n))
    print_unordered_multiset(s);

    auto it = s.find("def");
    if (it != s.end())
        cout << "Found: " << *it << endl;
    else
        cout << "Not found" << endl;
}