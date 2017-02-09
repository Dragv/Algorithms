#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <cstdio>

using namespace std;

template<class T>
class Node {
private:
  Node<T> * next;
  T element;

public:
  Node(){
    next = NULL;
    T = NULL;
  }
  void setNext(Node<T> next){
    this->next = next;
  }
  void setElement(T element){
    this->element = element;
  }
  Node<T> getNext(){
    return this->next;
  }
  T getElement(){
    return this->element;
  }
};
template<class T>
class linkedlist {
private:
  Node<T>* firstNode;
  int size;

  bool indexCheck(int index){
    return (index < 0 || index > this->size);
  }

public:
  linkedlist(){
    this->firstNode = new Node<T>();
    this->size = 0;
  }

  bool isEmpty(){
    return this->size == 0;
  }

  int size(){
    return this->size;
  }

  T get(int index){
    if (indexCheck(index)){
      throw invalid_argument("Index out of bound");
    }
  }

  int indexOf(T element){

  }

  T remove(int index){

  }

  void add(int index, T element){

  }
}
