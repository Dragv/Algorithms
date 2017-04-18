#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "compressedDisjointSet.h"

typedef pair<int, int> edge;

class graph{
private:
  int V, E;
  vector<pair<int, edge> > edges;
public:
  graph(int V, int E){
    this->V = V;
    this->E = E;
  }

  void add(int u, int v, int w) {
    edges.push_back(pair<int, edge>(w, edge(u, v)));
  }

  bool exists(int u, int v){
    for (vector< pair<int,edge> >::iterator i = edges.begin(); i != edges.end(); i++) {
      edge temp = i->second;
      if((temp.first == u && temp.second == v) || (temp.first == v && temp.second == u)){
        return true;
      }
    }
  }

  int kruskal(){
    int total = 0;
    compressedDisjoingSet *s = new compressedDisjoingSet(V);
    s->makeX();
    sort(edges.begin(), edges.end());
    for(vector<pair<int,edge> >::iterator i = edges.begin(); i != edges.end(); i++){
      int u = i->second.first;
      int v = i->second.second;
      int uSet = s->find(u);
      int vSet = s->find(v);
      if(uSet != vSet){
        total += i->first;
        s->Union(uSet, vSet);
      }
    }
    return total;
  }
};
