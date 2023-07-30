#include <iostream>
using namespace std;
int main()
{
    pair<int, int> p1(10, 20);
    pair<int, int> p2(10, 30);
    pair<int, int> p3(10, 20);
    cout << (p1 == p2) << endl;
    cout << (p1 == p3) << endl;
    cout << (p1 != p2) << endl;
    cout << (p1 != p3) << endl;
    cout << (p1 < p2) << endl;
    cout << (p1 <= p2) << endl;
    cout << (p1 > p2) << endl;
    cout << (p1 >= p2) << endl;
    pair<int, string> p;
    p = make_pair(10, "Hello");
    cout << p.first << " " << p.second << endl;
    pair<int, string> &pRef = p;
    pRef.first = 20;
    pRef.second = "World";
    cout << p.first << " " << p.second << endl;
    pair<int, int> p_array[3];
    p_array[0] = {1, 2};
    p_array[1] = {3, 4};
    p_array[2] = {5, 6};
    swap(p_array[0], p_array[2]);
    for (int i = 0; i < 3; i++)
        cout << p_array[i].first << " " << p_array[i].second << endl;
}