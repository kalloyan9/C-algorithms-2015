#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1000
#define INF 9999999
struct Edge
{
public:
    int vertex;
    int distance;

    Edge(int vertex, int distance)
    {
        this->vertex = vertex;
        this->distance = distance;
    }
    bool operator< (Edge const& other) const
    {
        return this->distance > other.distance;
    }
    bool operator> (Edge const& other) const
    {
        return this->distance < other.distance;
    }
};
vector<vector<Edge> > vertices(MAX_N);
vector<int> dijkstra(int from,int n)
{
    vector<int> distances;
    bool used[MAX_N];
    for (int i = 0; i < n; i++)
    {
        distances.push_back(INF);
        used[i] = false;
    }
    distances[from] = 0;
    priority_queue<Edge> queue;
    Edge start(from, 0);
    queue.push(start);

    while (!queue.empty())
    {
        Edge top = queue.top();
        queue.pop();
        used[top.vertex] = true;
        for (int i = 0, len = vertices[top.vertex].size(); i < len; i++)
        {
            Edge edge = vertices[top.vertex][i];

            int oldDistance = distances[edge.vertex];
            int newDistance = distances[top.vertex] + edge.distance;
            if (newDistance < oldDistance)
            {
                distances[edge.vertex] = newDistance;
                Edge newEdge(edge.vertex, newDistance);
                queue.push(newEdge);
            }
        }
        while (!queue.empty())
        {
            Edge edge = queue.top();
            if (!used[edge.vertex])
            {
                break;
            }
            queue.pop();
        }
    }
    return distances;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int start, end;
    cin >> start >> end;
    for (int i = 0; i < m; ++i)
    {
        int from, to, distance;
        cin >> from >> to >> distance;
        Edge e(to, distance);
        vertices[from].push_back(e);
    }
    vector<int> d = dijkstra(midle_1, n);
    cout << d[start];
    return 0;
}

/*
!!!
КОДЪТ Е ЗА НАСОЧЕН ГРАФ!
--------------------------------
А ЗА НЕНАСОЧЕН:
Edge e(to, distance);
vertices[from].push_back(e);

Edge q(from, distance);
vertices[to].push_back(q);
--------------------------------
*/
