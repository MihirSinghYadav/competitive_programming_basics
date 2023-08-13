#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int N = 1e5 + 10;
vector<int> tree[N];
int parents[N];

void dfs(int vertex, int parent = -1)
{
    parents[vertex] = parent;
    for (int child : tree[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int> answer;
    while (vertex != -1)
    {
        answer.push_back(vertex);
        vertex = parents[vertex];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    cout << "Enter number of vertices : ";
    int vertices;
    cin >> vertices;
    for (int i = 0; i < vertices - 1; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        tree[vertex1].push_back(vertex2);
        tree[vertex2].push_back(vertex1);
    }
    dfs(1);
    cout << "Enter two vertices to find LCA :";
    int x, y;
    cin >> x >> y;

    vector<int> path_x = path(x);
    cout << "Path of " << x << " : ";
    for (auto i : path_x)
        cout << i << " ";

    vector<int> path_y = path(y);
    cout << "\nPath of " << y << " : ";
    for (auto i : path_y)
        cout << i << " ";

    int minimum_length = min(path_x.size(), path_y.size());
    cout << endl;
    int lca = -1;

    for (int i = 0; i < minimum_length; i++)
    {
        if (path_x[i] == path_y[i])
            lca = path_x[i];
        else
            break;
    }
    cout << "LCA: " << lca << "\n";
}
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
6 7
*/