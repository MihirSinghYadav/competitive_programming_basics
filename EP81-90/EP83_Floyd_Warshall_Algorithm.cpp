#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 105;
const int INF = 1e9;
int dist[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                // if(dist[j][i] != INF && dist[i][k] != INF)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    cout << "Shortest distance between every pair of vertices: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "I"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
/*
Input
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
Output
Shortest distance between every pair of vertices:
0 1 3 3 2 4
I 0 2 2 1 3
I I 0 I 2 4
I I I 0 3 1
I I I I 0 2
I I I I I 0
*/