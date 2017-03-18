#include <iostream>
#include <stdexcept>
#include <cstring>
#include "minHeap.h"

using namespace std;

template<class T>
class Node;

template<class T>
ostream& operator<<(ostream& os, const Node<T>& dt);

template<class T>
class Node{
public:
  T element;
  float freq;
  string code;
  Node<T>* left = NULL;
  Node<T>* right = NULL;

  Node(Node<T> left, Node<T> right, float freq){
    this->freq = freq;
    this->left = left;
    this->right = right;
  }

  Node(T element, double freq){
    this->freq = freq;
    this->element = element;
    this->left = NULL;
    this->right = NULL;
  }

  ~Node() {
    delete &element;
    delete &freq;
    delete &left;
    delete &right;
  }

  bool operator<(const Node<T>& a){
    return this->freq < a.freq;
  }
  bool operator>(const Node<T>& a){
    return this->freq > a.freq;
  }
  void operator = (const Node& a) {
    this->freq = a.freq;
    this->element = a.element;
  }
  friend ostream& operator<< <>(ostream& os, const Node& dt);
};
template<class T>
ostream& operator<<(std::ostream& os, const Node<T>& dt){
    os << dt.freq << " " << dt.element;
    return os;
}

template<class T>
void preorder(Node<T>* x){
  if(x != NULL){
    cout << x->freq << " " << x->element << " " << x->code << endl;
    preorder(x->left);
    preorder(x->right);
  }
}

int main() {
  minHeap<Node<char>* >* m = new minHeap<Node<char>* >(27, new Node<char>('/', 1000));
  m->insert(new Node<char>('z', 0.1));
  m->insert(new Node<char>('q', 0.1));
  m->insert(new Node<char>('x', 0.2));
  m->insert(new Node<char>('j', 0.2));
  m->insert(new Node<char>('k', 0.6));
  m->insert(new Node<char>('v', 0.9));
  m->insert(new Node<char>('b', 1.3));
  m->insert(new Node<char>('p', 1.6));
  m->insert(new Node<char>('y', 1.6));
  m->insert(new Node<char>('r', 4.8));
  m->insert(new Node<char>('d', 3.5));
  m->insert(new Node<char>('l', 3.4));
  m->insert(new Node<char>('c', 2.6));
  m->insert(new Node<char>('u', 2.4));
  m->insert(new Node<char>('m', 2.1));
  m->insert(new Node<char>('w', 1.9));
  m->insert(new Node<char>('f', 1.8));
  m->insert(new Node<char>('g', 1.7));
  m->insert(new Node<char>('h', 4.9));
  m->insert(new Node<char>('s', 5.1));
  m->insert(new Node<char>('n', 5.5));
  m->insert(new Node<char>('i', 5.8));
  m->insert(new Node<char>('o', 5.9));
  m->insert(new Node<char>('a', 6.8));
  m->insert(new Node<char>('t', 7.7));
  m->insert(new Node<char>('e', 10.2));
  m->insert(new Node<char>(' ', 18.3));

  Node<char>* finalTree;

  for (int i = 1; i < m->getSize(); i++){
    Node<char>* z = new Node<char>('*', 0);
    Node<char>* x = m->pop();
    Node<char>* y = m->pop();
    x->code = "0";
    y->code = "1";
    z->left = x;
    z->right = y;
    z->freq = x->freq + y->freq;
    m->insert(z);
  }
  finalTree = m->pop();

  cout << *finalTree << '\n';

  //cout << *finalTree->left->left->left << endl;
  preorder(finalTree);

  return 0;
}
