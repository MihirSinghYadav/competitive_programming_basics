#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const long long N = 2e3 + 10;
long long parent[N];
long long sizes[N];

void make(long long v)
{
    parent[v] = v;
    sizes[v] = 1;
}

long long find(long long v)
{
    if (v == parent[v])
    {
        return v;
    }
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(long long a, long long b)
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
    long long n;
    cin >> n;
    vector<pair<long, long> > cities(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }
    vector<long long> c(n + 1), k(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    vector<pair<long long, pair<long long, long long> > > edges;
    for (long long i = 1; i <= n; i++)
    {
        edges.push_back(make_pair(c[i], make_pair(0, i)));
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
        {
            long long dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = dist * 1LL * (k[i] + k[j]);
            edges.push_back(make_pair(cost, make_pair(i, j)));
        }
    }
    for (long long i = 1; i <= n; i++)
        make(i);
    sort(edges.begin(), edges.end());
    long long total_path_cost = 0;
    vector<long long> power_stations;
    vector<pair<long, long> > connections;
    for (long long i = 0; i < n; i++)
    {
        long long wt = edges[i].first;
        long long x = edges[i].second.first;
        long long y = edges[i].second.second;
        if (find(x) == find(y))
            continue;
        Union(x, y);
        total_path_cost += wt;
        if (x == 0 || y == 0)
            power_stations.push_back(max(x, y));
        else
            connections.push_back(make_pair(x, y));
        // cout << "x = " << x << " y = " << y << " wt = " << wt << endl;
    }
    cout << total_path_cost << endl;
    cout << power_stations.size() << endl;
    for (long long station : power_stations)
        cout << station << " ";
    cout << endl;
    cout << connections.size() << endl;
    for (long long i = 0; i < connections.size(); i++)
        cout << connections[i].first << " " << connections[i].second << endl;
    return 0;
}
/*
Input
3
2 3
1 1
3 2
3 2 3
3 2 3
Output
2
*/