#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 10;
int graph1[N][N];
vector<pair<int, int>> graph2[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        // Adjacency matrix
        // O(n^2) space complexity
        graph1[v1][v2] = weight;
        graph1[v2][v1] = weight;

        // Adjacency list
        // O(n + m) space complexity
        graph2[v1].push_back({v2, weight});
        graph2[v2].push_back({v1, weight});
    }
    cout << "Adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Adjacency list: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto j : graph2[i])
        {
            cout << "(" << j.first << ", " << j.second << ") ";
        }
        cout << endl;
    }
}
/*
Input
6 9
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3
*/