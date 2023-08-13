#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
vector<int> tree[N];
int subtree_sum[N];
int value[N];

void dfs(int vertex, int parent = -1)
{
    subtree_sum[vertex] += value[vertex];
    cout << vertex << " " << parent << "\n";
    cout << subtree_sum[vertex] << "\n";
    for (int child : tree[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        cout << subtree_sum[vertex] << "\n";
    }
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
    dfs(1);
    long long answer = 0;
    for (int i = 2; i <= vertices; i++)
    {
        int part1 = subtree_sum[i];
        cout << part1 << " ";
        int part2 = subtree_sum[1] - part1;
        cout << part2 << "\n";
        answer = max(answer, (part1 * 1LL * part2) % M);
    }
    cout << answer;
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
*/