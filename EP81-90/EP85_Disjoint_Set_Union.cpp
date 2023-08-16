#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int sizes[N];

void make(int v)
{
    parent[v] = v;
    sizes[v] = 1;
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
    }
    int connected_count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            connected_count++;
        }
    }
    cout << "Connected Count : " << connected_count << endl;
}
// Time complexity
// Make set - O(1)
// Find - O(logn)
// Union - O(logn)
// Space complexity - O(n)
// Reverse Ackermann function - O(1)
// ammortized time complexity - O(1)