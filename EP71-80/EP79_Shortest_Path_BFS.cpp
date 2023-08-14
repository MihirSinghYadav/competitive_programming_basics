#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int INF = 1e9 + 10;

int visited[8][8];
int level[8][8] = {INF};

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

bool isValidMove(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(string source, string destination)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destinationX = getX(destination);
    int destinationY = getY(destination);
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    visited[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;
    while (!q.empty())
    {
        pair<int, int> current_vertex = q.front();
        int x = current_vertex.first, y = current_vertex.second;
        q.pop();
        for (auto move : movements)
        {
            int childX = move.first + x;
            int childY = move.second + y;
            if (!isValidMove(childX, childY))
                continue;
            if (!visited[childX][childY])
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                visited[childX][childY] = 1;
            }
        }
        if (level[destinationX][destinationY] != INF)
            break;
    }
    return level[destinationX][destinationY];
}
void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        reset();
        string source, destination;
        cin >> source >> destination;
        cout << bfs(source, destination) << endl;
    }
}
// Time complexity : O(V+E)

/*
Input
3
a1 h8
a1 c2
h8 c3

Output
6
1
4
*/