#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
vector<int> tree[N];
int visited[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    int count = 0;
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();
        cout << "Current Vertex : " << current_vertex;
        for (int child : tree[current_vertex])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                level[child] = level[current_vertex] + 1;
            }
            count++;
        }
        cout << endl;
    }
    cout << "Cycle Count : " << count << endl;
}

int main()
{
    int vertices;
    cin >> vertices;
    for (int i = 0; i < vertices - 1; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        tree[vertex1].push_back(vertex2);
        tree[vertex2].push_back(vertex1);
    }

    bfs(1);
    cout << "Level : " << endl;
    for (int i = 1; i <= vertices; i++)
    {
        cout << i << " : " << level[i] << endl;
    }
}
// Time complexity : O(V+E)

/*
Input
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
*/