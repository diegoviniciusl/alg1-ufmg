#include "FirstTaskSolver.h"

int MVC(vector<vector<int> > &graph, vector<bool> &isInMVC, vector<bool> &isVisited, int node)
{
    isVisited[node] = true;
    if (graph[node].size() == 1)
    {
        return 0;
    }
    int MVCResult = 0;
    for (int i = 0; i < graph[node].size(); ++i)
    {
        if (isVisited[graph[node][i]])
        {
            continue;
        }

        MVCResult += MVC(graph, isInMVC, isVisited, graph[node][i]);

        if (isInMVC[node] || isInMVC[graph[node][i]])
        {
            continue;
        }

        ++MVCResult;
        isInMVC[node] = true;
    }
    return MVCResult;
}

int nonTerminalNode(vector<vector<int> > &graph)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[i].size() > 1)
        {
            return i;
        }
    }
    return -1;
}

void firstTaskSolver(vector<vector<int> > &graph)
{
    vector<bool> isInMVC = vector<bool>(graph.size(), false);
    vector<bool> isVisited = vector<bool>(graph.size(), false);
    cout << MVC(graph, isInMVC, isVisited, nonTerminalNode(graph)) << endl;
}
