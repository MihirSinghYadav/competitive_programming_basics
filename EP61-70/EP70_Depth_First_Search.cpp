#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

void dfs(int vertex)
{
    // Take action on vertex after entering the vertex
    // if (visited[vertex]) return;
    cout << vertex << " ";
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        cout << "Parent: " << vertex << " Child: " << child << "\n";
        // Take action on child before entering the child node
        if (visited[child])
            continue;
        //////////////////////////////////////////////////////////////////
        dfs(child);
        //////////////////////////////////////////////////////////////////
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
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
    cout << "DFS Traversal in graph: " << endl;
    dfs(1);
}
// Time complexity : O(n + m)

/*
Input
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/