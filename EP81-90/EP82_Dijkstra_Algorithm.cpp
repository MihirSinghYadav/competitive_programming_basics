#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int dijkstra(int source, int n, vector<pair<int, int>> graph[])
{
    vector<int> visited(N, 0);
    vector<int> distance(N, INF);
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<pair<int, int>> sets;
    sets.insert({0, source});
    distance[source] = 0;
    while (sets.size() > 0)
    {
        auto node = *sets.begin();
        int vertex = node.second;
        int vertex_distance = node.first;
        sets.erase(sets.begin());
        if (visited[vertex] == 1)
            continue;
        visited[vertex] = 1;
        for (auto child : graph[vertex])
        {
            int child_vertex = child.first;
            int weight = child.second;
            if (distance[vertex] + weight < distance[child_vertex])
            {
                distance[child_vertex] = distance[vertex] + weight;
                sets.insert({distance[child_vertex], child_vertex});
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (distance[i] == INF)
            return -1;
        else
            answer = max(answer, distance[i]);
    }
    return answer;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    cout << "Hello world";
    cout << "n: " << n << " k: " << k << endl;
    vector<pair<int, int>> graph[N];
    for (auto time : times)
    {
        graph[time[0]].push_back({time[1], time[2]});
    }
    return dijkstra(k, n, graph);
}

int main()
{
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> times(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
        cout << times[i][0] << " " << times[i][1] << " " << times[i][2] << endl;
    }
    cin >> k;
    cout << networkDelayTime(times, n, k) << endl;

    return 0;
}

/*
Input
4 3
2 1 1
2 3 1
3 4 1
2
Output
2
*/