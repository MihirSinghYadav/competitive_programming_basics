#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {4, 5, 5, 4, 1, 85, 8, 1, 531, 56, 4, 1, 3244, 65, 1, 654, 65, 16, 51, 654, 651};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    vector<int> v = {4, 5, 5, 4, 1, 85, 8, 1, 531, 56, 4, 1, 3244, 65, 1, 654, 65, 16, 51, 654, 651};
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}