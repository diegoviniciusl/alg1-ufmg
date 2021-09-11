#include <fstream>
#include "FirstTaskSolver.h"
#include "SecondTaskSolver.h"

void addVertex(vector<vector<int> > &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<vector<int> > createGraph(string file)
{
    ifstream fileStream;
    int nodes, edges, u, v;
    fileStream.open(file, ios::in);
    fileStream >> nodes >> edges;
    vector<vector<int> > graph(nodes);
    if (fileStream.is_open())
    {
        for (int i = 0; i < edges; ++i)
        {
            fileStream >> u >> v;
            addVertex(graph, u, v);
        }
        fileStream.close();
    }
    return graph;
}

int main(int argc, char *const argv[])
{
    if (argc < 2)
    {
        return -1;
    }

    string task = argv[1];
    string file = argv[2];
    vector<vector<int> > graph = createGraph(file);

    if (task == "tarefa1")
    {
        firstTaskSolver(graph);
    }
    else if (task == "tarefa2")
    {
        secondTaskSolver(graph);
    }

    return 0;
}