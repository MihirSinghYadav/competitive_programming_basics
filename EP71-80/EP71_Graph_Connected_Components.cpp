#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
vector<vector<int>> connected_components;
vector<int> current_connected_component;

void dfs(int vertex)
{
    // Take action on vertex after entering the vertex
    // if (visited[vertex]) return;
    current_connected_component.push_back(vertex);
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
    int count = 0;
    for (int i = 1; i <= vertices; i++)
    {
        if (visited[i])
            continue;
        current_connected_component.clear();
        dfs(i);
        connected_components.push_back(current_connected_component);
        count++;
    }
    cout << endl;
    cout << "Connected components size: \n"
         << connected_components.size() << "\n";
    for (auto current_component : connected_components)
    {
        cout << "Component: ";
        for (auto vertex : current_component)
        {
            cout << vertex << " ";
        }
        cout << "\n";
    }
}
// Time complexity : O(n + m)

/*
Input
8 5
1 2
2 3
2 4
3 5
6 7
*/