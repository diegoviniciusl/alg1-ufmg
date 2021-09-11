#include "SecondTaskSolver.h"

vector<Edge> createEdges(vector<vector<int> > &graph)
{
    vector<Edge> edges;
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            Edge edge;
            edge.u = i;
            edge.v = graph[i][j];
            edges.push_back(edge);
        }
    }
    return edges;
}

vector<int> aproxMVC(vector<Edge> &edges)
{
    vector<int> solution;
    while (!edges.empty())
    {
        solution.push_back(edges[0].u);
        solution.push_back(edges[0].v);
        int initialSize = edges.size();
        for (int i = 1; i < initialSize; ++i)
        {
            if (edges[i].u == edges[0].u || edges[i].v == edges[0].v || edges[i].u == edges[0].v || edges[i].v == edges[0].u)
            {
                edges.erase(edges.begin() + i);
                --initialSize;
                --i;
            }
        }
        edges.erase(edges.begin());
    }
    return solution;
}

void secondTaskSolver(vector<vector<int> > &graph)
{
    vector<Edge> edges = createEdges(graph);
    vector<int> solution = aproxMVC(edges);
    cout << solution.size() << endl;
    for (int i = 0; i < solution.size(); ++i)
    {
        cout << solution[i] << endl;
    }
}
