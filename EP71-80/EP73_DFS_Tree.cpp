#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 1e5 + 10;
vector<int> tree[N];
int depth[N], height[N];

void dfs(int vertex, int parent = 0)
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
        height[vertex] = max(height[vertex], height[child] + 1);
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
    cout << "DFS Traversal in Tree: " << endl;
    dfs(1);
    cout << "Vertex Depth Height" << endl;
    for (int i = 1; i <= vertices; i++)
        cout << setw(3) << i << setw(7) << depth[i] << setw(6) << height[i] << endl;
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
DFS Traversal in Tree:
Vertex Depth Height
  1      0     4
  2      1     3
  3      1     3
  4      2     2
  5      2     2
  6      3     0
  7      3     0
  8      3     1
  9      3     0
 10      3     1
 11      4     0
 12      4     0
 13      1     0
*/