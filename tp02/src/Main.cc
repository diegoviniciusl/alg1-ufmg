#include "Node.h"
#include <stack>
#include <map>

vector<Node *> transposeGraph(vector<Node *> &graph)
{
    vector<Node *> transposedGraph;
    for (int i = 0; i < graph.size(); ++i)
    {
        transposedGraph.push_back(new Node(i));
    }
    for (int i = 0; i < graph.size(); ++i)
    {
        vector<Node *> neighbors = graph[i]->getNeighbors();
        for (int j = 0; j < neighbors.size(); ++j)
        {
            transposedGraph[neighbors[j]->getId()]->addNeighbor(transposedGraph[graph[i]->getId()]);
        }
    }
    return transposedGraph;
}

void dfs(Node *node, vector<bool> &visited, map<int, int> &stronglyConnectedComponents, int group)
{
    visited[node->getId()] = true;
    stronglyConnectedComponents[node->getId()] = group;

    vector<Node *> neighbors = node->getNeighbors();
    for (int i = 0; i < neighbors.size(); ++i)
    {
        if (!visited[neighbors[i]->getId()])
        {
            dfs(neighbors[i], visited, stronglyConnectedComponents, group);
        }
    }
}

void dfs(Node *node, vector<bool> &visited, stack<Node *> &stack)
{
    visited[node->getId()] = true;

    vector<Node *> neighbors = node->getNeighbors();
    for (int i = 0; i < neighbors.size(); ++i)
    {
        if (!visited[neighbors[i]->getId()])
        {
            dfs(neighbors[i], visited, stack);
        }
    }

    stack.push(node);
}

map<int, int> kosaraju(vector<Node *> &graph)
{
    stack<Node *> stack;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i)
    {
        if (visited[i] == false)
        {
            dfs(graph[i], visited, stack);
        }
    }
    vector<Node *> transposedGraph = transposeGraph(graph);
    for (int i = 0; i < graph.size(); ++i)
    {
        visited[i] = false;
    }
    map<int, int> stronglyConnectedComponents;
    int group = 0;
    while (stack.empty() == false)
    {
        Node *node = stack.top();
        stack.pop();
        Node *transposedGraphNode = transposedGraph[node->getId()];
        if (visited[transposedGraphNode->getId()] == false)
        {
            dfs(transposedGraphNode, visited, stronglyConnectedComponents, group);
            group++;
        }
    }
    return stronglyConnectedComponents;
}

vector<Node *> createGraph()
{
    vector<Node *> graph;
    int vertices, edges;
    cin >> vertices;
    cin >> edges;
    for (int i = 0; i < vertices; ++i)
    {
        graph.push_back(new Node(i));
    }
    for (int i = 0; i < edges; ++i)
    {
        int from, to;
        cin >> from;
        cin >> to;
        graph[from - 1]->addNeighbor(graph[to - 1]);
    }
    return graph;
}

int countGroups(map<int, int> &stronglyConnectedComponents)
{
    map<int, int>::iterator it;
    int groups = -1;
    for (it = stronglyConnectedComponents.begin(); it != stronglyConnectedComponents.end(); ++it)
    {
        if (it->second > groups)
        {
            groups = it->second;
        }
    }
    return groups + 1;
}

vector<Node *> createDag(vector<Node *> &graph, map<int, int> &stronglyConnectedComponents)
{
    int groups = countGroups(stronglyConnectedComponents);
    vector<Node *> dag;
    for (int i = 0; i < groups; ++i)
    {
        dag.push_back(new Node(i));
    }
    for (int i = 0; i < graph.size(); ++i)
    {
        vector<Node *> neighbors = graph[i]->getNeighbors();
        for (int j = 0; j < neighbors.size(); ++j)
        {
            int firstGroup = stronglyConnectedComponents[graph[i]->getId()];
            int secondGroup = stronglyConnectedComponents[neighbors[j]->getId()];
            if (firstGroup != secondGroup)
            {
                dag[firstGroup]->addNeighbor(dag[secondGroup]);
            }
        }
    }
    return dag;
}

int getMaxDegree(vector<Node *> dag)
{
    int zeroedInDegrees = 0;
    int zeroedOutDegrees = 0;
    for (int i = 0; i < dag.size(); ++i)
    {
        if (dag[i]->getInDegree() == 0)
        {
            zeroedInDegrees++;
        }
        if (dag[i]->getOutDegree() == 0)
        {
            zeroedOutDegrees++;
        }
    }
    return zeroedInDegrees > zeroedOutDegrees ? zeroedInDegrees : zeroedOutDegrees;
}

int main()
{
    vector<Node *> graph = createGraph();
    map<int, int> stronglyConnectedComponents = kosaraju(graph);
    vector<Node *> dag = createDag(graph, stronglyConnectedComponents);
    cout << getMaxDegree(dag) << endl;
    return 0;
}