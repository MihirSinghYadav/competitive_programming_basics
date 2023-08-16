#include <iostream>
#include <set>
using namespace std;
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
const int N = 1e5 + 10;
int parent[N];
int sizes[N];
multiset<int> s;

void make(int v)
{
    parent[v] = v;
    sizes[v] = 1;
    s.insert(1);
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    // Path compression
    return parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
    s.erase(s.find(sizes[a]));
    s.erase(s.find(sizes[b]));
    s.insert(sizes[a] + sizes[b]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // Union by size
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        merge(a, b);
        sizes[a] += sizes[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
        if (s.size() == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            int mn = *(s.begin());
            int mx = *(--s.end());
            cout << *s.rbegin() - *s.begin() << endl;
        }
    }
}

/*
Input
2 1
1 2
Output
0
*/