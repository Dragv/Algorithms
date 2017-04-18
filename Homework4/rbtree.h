#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "rbnode.h"

using namespace std;

class rbtree{
private:
  int size;
  rbnode* root;
  rbnode* nil;
public:
  rbtree(){
    this->size = 0;
    this->nil = new rbnode();
    this->root = this-> nil;
    this->nil->parent = this->nil;
  }

  int getSize(){
    return size;
  }

  void insert(int key) {
    rbnode* z = new rbnode(key);
    rbnode* y = this->nil;
    rbnode* x = this->root;

    while(x != this->nil){
      y = x;
      if(z->key < x->key)
        x = x->left;
      else
        x = x->right;
    }
    z->parent = y;
    if(y == this->nil){
      this->root = z;
    }
    else if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
    z->left = this->nil;
    z->right = this->nil;
    z->color = 0;

    this->size++;

    fixup(z);
  }

  void rotateLeft(rbnode* x) {
    rbnode *y = x->right;
    x->right = y->left;
    if(y->left != this->nil){
      y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == this->nil){
      this->root = y;
    }
    else if(x == x->parent->left){
      x->parent->left = y;
    }
    else{
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rotateRight(rbnode* x) {
    rbnode *y = x->left;
    x->left = y->right;
    if(y->right != this->nil){
      y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == this->nil){
      this->root = y;
    }
    else if(x == x->parent->right){
      x->parent->right = y;
    }
    else{
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  void fixup(rbnode* x){
    rbnode *y;
    while(x->parent->color == 0){
      if(x->parent == x->parent->parent->left) {
        y = x->parent->parent->right;
        if(y->color == 0) {
          x->parent->color = 1;
          y->color = 1;
          x->parent->parent->color = 0;
          x = x->parent->parent;
        }
        else {
          if(x == x->parent->right) {
            x = x->parent;
            rotateLeft(x);
          }
          x->parent->color = 1;
          x->parent->parent->color = 0;
          rotateRight(x->parent->parent);
        }
      }
      else {
        y = x->parent->parent->left;
        if(y->color == 0) {
          x->parent->color = 1;
          y->color = 1;
          x->parent->parent->color = 0;
          x = x->parent->parent;
        }
        else {
          if(x == x->parent->left) {
            x = x->parent;
            rotateRight(x);
          }
          x->parent->color = 1;
          x->parent->parent->color = 0;
          rotateLeft(x->parent->parent);
        }
      }
    }
    this->root->color = 1;
  }
};

#endif
