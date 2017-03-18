#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <iterator>
#include <cmath>
#define DEFAULT_SIZE = 30;

using namespace std;

template<class T>
class heap {
private:
  int size;
  int* maxHeap;
  int index;

public:

  heap(){
    this->maxHeap = NULL;
    this->size = 0;
  }

  void insert (int element){
    size++;
    int * temp = new int[this->size];
    for (int i = 0; i < this->size - 1; i++){
      temp[i] = this->maxHeap[i];
    }
    temp[this->size - 1] = element;
    delete[] this->maxHeap;
    this->maxHeap = temp;
  }

  void MaxHeapify(int index){
    int l = 2*index;
    int r = 2*index+1;
    int largest = 0;
    if ((l <= this->size) && (this->maxHeap[l] > this->maxHeap[index])){
      largest = l;
    } else {
      largest = index;
    }
    if ((r <= this->size) && (this->maxHeap[r] > this->maxHeap[largest])){
      largest = r;
    }
    int temp;
    if (largest != index){
      temp = this->maxHeap[index];
      this->maxHeap[index] = this->maxHeap[largest];
      this->maxHeap[largest] = temp;
      this->MaxHeapify(largest);
    }
    return;
  }

  void buildMaxHeap(){
    for (int i = floor((this->size-1)/2); i >= 0; i--){
      MaxHeapify(i);
    }
  }
};

#endif
