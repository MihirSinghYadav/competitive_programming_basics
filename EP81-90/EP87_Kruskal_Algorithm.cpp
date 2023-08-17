#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        edges.push_back(make_pair(wt, make_pair(x, y)));
    }
    for (int i = 1; i <= n; i++)
        make(i);
    sort(edges.begin(), edges.end());
    int total_path_cost = 0;
    for (int i = 0; i < m; i++)
    {
        int wt = edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if (find(x) == find(y))
            continue;
        Union(x, y);
        total_path_cost += wt;
        cout << "x = " << x << " y = " << y << " wt = " << wt << endl;
    }
    cout << "Total path cost: " << total_path_cost << endl;
    return 0;
}
/*
Input
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
Output
2
*/