#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

using namespace std;

class Node{
public:
  vector<Node *> aList;
  Node * pre;
  unsigned int distance;
};

class graph{
public:
  vector<Node *> v;
};

#endif
