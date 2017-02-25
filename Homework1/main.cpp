#include <iostream>
#include "linkedlist.h"
#include "heap.h"

using namespace std;

int main(){
  linkedlist<int>* a = new linkedlist<int>();
  //heap* heapsort = new heap();
  for (int i = 0; i < 11; i++){
    cout << i+1 << endl;
    a->add(i, i+1);
  }
  for (int i = 0; i < 11; i++){
    cout << a->get(i) << endl;
  }
}
