#ifndef COMPRESSEDDISJOINTSET_H
#define COMPRESSEDDISJOINTSET_H

#include <iostream>

using namespace std;

class compressedDisjoingSet{
private:
  int* set;
  int* rank;
  int* p;
  int n;
  int c;
public:
  compressedDisjoingSet(int n){
    this->set = new int[n];
    this->rank = new int[n];
    this->p = new int[n];
    for (int i = 0; i < n; i++){
      this->set[i] = 0;
      this->rank[i] = 0;
    }
    this->n = n;
    this->c = n;
  }

  void make(int n) {
    this->p[n] = n;
    this->set[n] = 1;
  }

  void makeX() {
    for (int i = 0; i < this->c; i++)
      make(i);
  }

  int find(int n) {
    if(this->p[n] != n)
      this->p[n] = find(this->p[n]);
    return this->p[n];
  }

  void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y){
      return;
    }
    if (this->rank[x] > this->rank[y]){
      this->p[y] = x;
      this->set[x] += this->set[y];
    } else {
      this->p[x] = this->p[y];
      this->set[this->p[y]] += this->set[x];
    }
    if (this->rank[x] == this->rank[y]){
      this->rank[y]++;
    }
    this->c--;
  }

};

#endif
