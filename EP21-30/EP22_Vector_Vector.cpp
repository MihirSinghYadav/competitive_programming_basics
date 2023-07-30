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
    vector<vector<int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    v[0].push_back(10);
    cout << "Output: " << endl;
    for (int i = 0; i < N; i++)
    {
        printVector(v[i]);
    }
    cout << v[0][1] << endl;
}