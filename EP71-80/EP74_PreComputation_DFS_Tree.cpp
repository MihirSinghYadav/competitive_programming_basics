#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
/*
Given Q queries, Q <= 10^5
In each query given V,
print the subtree sum of V, Number of even numbers in subtree of V
*/
const int N = 1e5 + 10;
vector<int> tree[N];
int subtree_sum[N];
int even_count[N];

void dfs(int vertex, int parent = 0)
{
    // Take action on vertex after entering the vertex
    // if (visited[vertex]) return;
    if (vertex % 2 == 0)
        even_count[vertex]++;
    subtree_sum[vertex] += vertex;
    for (int child : tree[vertex])
    {
        // Take action on child before entering the child node
        if (child == parent)
            continue;
        //////////////////////////////////////////////////////////////////
        dfs(child, vertex);
        //////////////////////////////////////////////////////////////////
        // Take action on child after exiting the child node
        subtree_sum[vertex] += subtree_sum[child];
        even_count[vertex] += even_count[child];
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
    cout << "Vertex SubtreeSum EvenCount" << endl;
    for (int i = 0; i <= vertices; i++)
    {
        cout << setw(3) << i << setw(10) << subtree_sum[i] << setw(10) << even_count[i] << endl;
    }

    // int queries;
    // cout << "Enter the number of queries: ";
    // cin >> queries;
    // while (queries--)
    // {
    //     int vertex;
    //     cin >> vertex;
    //     cout << "Subtree sum of " << vertex << " is " << endl;
    //     cout << subtree_sum[vertex] << " " << even_count[vertex] << endl;
    // }
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
Vertex SubtreeSum EvenCount
  0         0         0
  1        91         6
  2        33         4
  3        44         2
  4        41         2
  5        31         3
  6         6         1
  7         7         0
  8        20         2
  9         9         0
 10        21         1
 11        11         0
 12        12         1
 13        13         0
*/