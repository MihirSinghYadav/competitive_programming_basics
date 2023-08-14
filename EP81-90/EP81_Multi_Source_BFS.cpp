#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int value[N][N];
int visited[N][N];
int level[N][N];
int n, m;

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs()
{
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maximum = max(maximum, value[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maximum == value[i][j])
            {
                q.push({i, j});
                level[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }
    int answer = 0;
    while (!q.empty())
    {
        auto current = q.front();
        int x = current.first;
        int y = current.second;
        q.pop();
        for (auto movement : movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;
            if (!isValid(childX, childY))
                continue;
            if (visited[childX][childY])
                continue;
            q.push({childX, childY});
            level[childX][childY] = level[x][y] + 1;
            visited[childX][childY] = 1;
            answer = max(answer, level[childX][childY]);
        }
    }
    return answer;
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> value[i][j];
            }
        }

        cout << "Answer : " << bfs() << endl;
    }
}
/*
Input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
*/