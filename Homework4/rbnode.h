#ifndef RBNODE_H
#define RBNODE_H

#include <iostream>

using namespace std;

class rbnode{
public:
  int key;
  bool color;
  rbnode* left;
  rbnode* right;
  rbnode* parent;

  rbnode(int k){
    this->key = k;
    this->left = this->right = this->parent = NULL;
    color = 0;
  }

  rbnode(){
    this->left = this->right = this->parent = NULL;
    color = 1;
  }
};

#endif
