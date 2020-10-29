#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define INF 9999999

struct Edge
{
    int StartNode;

    int EndNode;

    int Weight;

    Edge(int StartNode, int EndNode, int Weight)
    {
        this->StartNode = StartNode;
        this->EndNode = EndNode;
        this->Weight = Weight;
    }

    bool operator < (Edge const& other) const
    {
        return this->Weight < other.Weight;
    }

    bool operator > (Edge const& other) const
    {
        return this->Weight > other.Weight;
    }
};

void FindMinimumSpanningTree(vector<Edge> edges, vector<Edge>& mpd, int treesCount , int n)
{
    int used[MAX_N];
    for(auto edge = edges.begin(); edge != edges.end(); edge++)
    {
        if (used[edge->StartNode] == 0) /// not visited
        {
            if (used[edge->EndNode] == 0) /// both ends are not visited
            {
                used[edge->StartNode] = used[edge->EndNode] = treesCount;
                treesCount++;
            }
            else
            {
                /// attach the start node to the tree of the end node
                used[edge->StartNode] = used[edge->EndNode];
            }
            mpd.push_back(*edge);
        }
        else /// the start is part of a tree
        {
            if (used[edge->EndNode] == 0)
            {
                ///attach the end node to the tree;
                used[edge->EndNode] = used[edge->StartNode];
                mpd.push_back(*edge);
            }

                for (int i = 0; i < n + 1; i++)
                {
                    if (used[i] == oldTreeNumber)
                    {
                        used[i] = used[edge->StartNode];
                    }
                }
                mpd.push_back(*edge);
            }
        }
    }
}
int main()
{
    vector<Edge> edges;
    vector<Edge> mpd;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int from, to, distance;
        cin >> from >> to >> distance;
        Edge e(from, to, distance);
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end());
    int treesCount = 1;
    FindMinimumSpanningTree(edges, mpd, treesCount , n);
    for(int i = 0; i < mpd.size(); i++)
    {
        cout << mpd[i].StartNode << ' ' << mpd[i].EndNode << endl;
    }
    return 0;
}            else if (used[edge->EndNode] != used[edge->StartNode]) // combine the trees
            {
                int oldTreeNumber = used[edge->EndNode];

                for (int i = 0; i < n + 1; i++)
                {
                    if (used[i] == oldTreeNumber)
                    {
                        used[i] = used[edge->StartNode];
                    }
                }
                mpd.push_back(*edge);
            }
        }
    }
}
int main()
{
    vector<Edge> edges;
    vector<Edge> mpd;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int from, to, distance;
        cin >> from >> to >> distance;
        Edge e(from, to, distance);
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end());
    int treesCount = 1;
    FindMinimumSpanningTree(edges, mpd, treesCount , n);
    for(int i = 0; i < mpd.size(); i++)
    {
        cout << mpd[i].StartNode << ' ' << mpd[i].EndNode << endl;
    }
    return 0;
}
/*
6
1 3 5
1 2 4
1 4 9
2 4 2
3 4 20
5 6 12
*/
