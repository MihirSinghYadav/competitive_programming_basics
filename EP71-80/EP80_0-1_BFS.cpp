#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INF);
int vertices, edges;

int bfs()
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop_front();

        for (auto child : graph[current_vertex])
        {
            int child_vertex = child.first;
            int weight = child.second;
            if (level[current_vertex] + weight < level[child_vertex])
            {
                level[child_vertex] = level[current_vertex] + weight;
                if (weight == 0)
                    q.push_front(child_vertex);
                else
                    q.push_back(child_vertex);
            }
        }
    }
    return level[vertices] == INF ? -1 : level[vertices];
}

int main()
{
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back({vertex2, 0});
        graph[vertex2].push_back({vertex1, 1});
    }
    cout << bfs() << endl;
}

/*
Input
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5
Output
2
*/
