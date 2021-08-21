#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node(int id);
    int getId();
    int getInDegree();
    int getOutDegree();
    vector<Node *> getNeighbors();
    void increaseInDegree();
    void addNeighbor(Node *);

private:
    int id;
    int outDegree;
    int inDegree;
    vector<Node *> neighbors;
};
#endif
