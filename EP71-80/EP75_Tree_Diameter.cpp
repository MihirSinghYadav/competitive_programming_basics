#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 1e5 + 10;
vector<int> tree[N];
int depth[N];

void dfs(int vertex, int parent = -1)
{
    // Take action on vertex after entering the vertex
    // if (visited[vertex]) return;
    for (int child : tree[vertex])
    {
        // Take action on child before entering the child node
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        //////////////////////////////////////////////////////////////////
        dfs(child, vertex);
        //////////////////////////////////////////////////////////////////
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    for (int i = 0; i < vertices - 1; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        tree[vertex1].push_back(vertex2);
        tree[vertex2].push_back(vertex1);
    }
    dfs(1);
    int max_depth = -1;
    int max_depth_vertex = -1;
    for (int i = 1; i <= vertices; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_depth_vertex = i;
        }
        depth[i] = 0;
    }
    dfs(max_depth_vertex);
    max_depth = -1;
    for (int i = 1; i <= vertices; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
        }
    }
    cout << "Diameter of the tree is: " << max_depth << endl;
}
// Time complexity : O(n + m)

/*
Input
13
1 2
1 3
1 13
2 5
3 4
5 6
4 7
5 8
8 12
4 9
4 10
10 11
Output
Diameter of the tree is: 8
*/