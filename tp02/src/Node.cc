#include "Node.h"

Node::Node(int id)
{
    this->id = id;
    this->outDegree = 0;
    this->inDegree = 0;
}

int Node::getId()
{
    return this->id;
}

int Node::getInDegree()
{
    return this->inDegree;
}

int Node::getOutDegree()
{
    return this->outDegree;
}

vector<Node *> Node::getNeighbors()
{
    return this->neighbors;
}

void Node::increaseInDegree()
{
    this->inDegree += 1;
}

void Node::addNeighbor(Node *node)
{
    this->neighbors.push_back(node);
    this->outDegree += 1;
    node->increaseInDegree();
}
