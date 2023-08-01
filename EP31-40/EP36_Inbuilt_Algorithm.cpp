#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    cout << "Vector : " << endl;
    vector<int> v = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    int ct = count(v.begin(), v.end(), 4);

    cout << "Min : " << min << endl;
    cout << "Max : " << max << endl;
    cout << "Sum : " << sum << endl;
    cout << "Count : " << ct << endl;

    int element = find(v.begin(), v.end(), 10) - v.begin();
    if (element == v.size())
        cout << "Element not found" << endl;
    else
        cout << "Element : " << element << endl;

    reverse(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    string s = "Quick Brown Fox Jumps Over The Lazy Dog";
    reverse(s.begin(), s.end());
    cout << s << endl;

    cout << "Array : " << endl;
    int a[10] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int min1 = *min_element(a, a + 10);
    int max1 = *max_element(a, a + 10);
    int sum1 = accumulate(a, a + 10, 0);
    int ct1 = count(a, a + 10, 4);

    cout << "Min : " << min1 << endl;
    cout << "Max : " << max1 << endl;
    cout << "Sum : " << sum1 << endl;
    cout << "Count : " << ct1 << endl;

    int element1 = find(a, a + 10, 10) - a;
    if (element1 == 10)
        cout << "Element not found" << endl;
    else
        cout << "Element : " << element1 << endl;

    reverse(a, a + 10);
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}