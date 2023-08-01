#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << [](int x, int y)
    { return x + y; }(4, 7)
         << endl;

    auto sum = [](int x, int y)
    { return x + y; };
    cout << sum(4, 7) << endl;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    cout << "all_of : " << all_of(v.begin(), v.end(), [](int x)
                                  { return x > 0; })
         << endl;

    cout << "any_of : " << any_of(v.begin(), v.end(), [](int x)
                                  { return x > 0; })
         << endl;

    cout << "none_of : " << none_of(v.begin(), v.end(), [](int x)
                                    { return x > 0; })
         << endl;
}