#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> v(10, 3);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }
    v.pop_back();
    cout << v.size() << endl;
    printVector(v);
}