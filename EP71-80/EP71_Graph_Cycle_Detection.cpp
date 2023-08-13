#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
vector<vector<int>> connected_components;
vector<int> current_connected_component;

bool dfs(int vertex, int parent)
{
    // Take action on vertex after entering the vertex
    // if (visited[vertex]) return;
    visited[vertex] = true;
    bool cycle = false;
    for (int child : graph[vertex])
    {
        if (visited[child] && child == parent)
            continue;
        if (visited[child])
            return true;
        // Take action on child before entering the child node

        //////////////////////////////////////////////////////////////////
        cycle |= dfs(child, vertex);
        //////////////////////////////////////////////////////////////////
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
    return cycle;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    bool cycle = false;
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            bool cycle = dfs(i, 0);
            if (cycle)
            {
                cout << "Cycle detected" << endl;
                return 0;
            }
        }
    }
    cout << "No cycle detected" << endl;
}
// Time complexity : O(n + m)

/*
Input
8 6
1 2
2 3
2 4
3 5
6 7
1 5
*/