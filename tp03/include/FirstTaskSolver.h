#ifndef FIRST_TASK_SOLVER_H
#define FIRST_TASK_SOLVER_H

#include <vector>
#include <iostream>

using namespace std;

int MVC(vector<vector<int> > &graph, int node, vector<bool> &inVertexCover, vector<bool> &visitedNodes);

int nonTerminalNode(vector<vector<int> > &graph);

void firstTaskSolver(vector<vector<int> > &graph);

#endif