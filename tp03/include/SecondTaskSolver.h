#ifndef SECOND_TASK_SOLVER_H
#define SECOND_TASK_SOLVER_H

#include <vector>
#include <iostream>

using namespace std;

class Edge
{
public:
    int u;
    int v;
};

vector<Edge> createEdges(vector<vector<int> > &graph);

vector<int> aproxMVC(vector<Edge> &edges);

void secondTaskSolver(vector<vector<int> > &graph);

#endif