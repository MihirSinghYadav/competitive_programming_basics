#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    cout << "Size: " << v.size() << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v[N];
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    cout << "Output: " << endl;
    for (int i = 0; i < N; i++)
    {
        printVector(v[i]);
    }
}