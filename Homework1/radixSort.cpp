#include <iostream>
#include <queue>
#include <random>
#include <fstream>
#include <stdio.h>

using namespace std;

void radixSort (int toBeSorted[], int lengthOfArray, int k){
  int Radix = 10;
  int power = 1;
  int digit;
  int index;
  int counter = 0;
  queue<int>* digitQueues [10];
  queue<int>* indexQueues [10];
  int list[lengthOfArray];
  for (int i = 0; i < lengthOfArray; i++){
    list[i] = i;
  }
  for (int i = 0; i < Radix; i++){
    digitQueues[i] = new queue<int>();
    indexQueues[i] = new queue<int>();
  }
  for (int i = 0; i < k; i++){
    int size = lengthOfArray;
    for (int j = 0; j < size; j++){
      digit = toBeSorted[j];
      index = list[j];
      digitQueues[(digit/power) % Radix]->push(digit);
      indexQueues[(digit/power) % Radix]->push(index);
    }
    for (int j = 0; j < Radix; j++) {
      while (!digitQueues[j]->empty()) {
        toBeSorted[counter] = digitQueues[j]->front();
        digitQueues[j]->pop();
        list[counter] = indexQueues[j]->front();
        indexQueues[j]->pop();
        counter++;
      }
    }
    counter = 0;
    power *= 10;
  }
}


int main() {

  ofstream randomcase("./dataRadix/radixRandomCase.txt");

  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // random number engine
  uniform_int_distribution<int> uni(1000, 9999);

  for (int i = 0; i < 10000; i+=10) {
    int array [1000];
    int n = (sizeof(array)/sizeof(*array));
    randomcase << i << ",";

    // insert
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      array[j] = r;
    }

    clock_t start = clock();
    randomcase << (clock() - start) << ",";
    radixSort(array, n, 4);

  }
  randomcase.close();

  ofstream bestcase("./dataRadix/radixBestCase.txt");

  random_device rd1;   // Used to initialize seed engine
  mt19937 rng1(rd());  // random number engine
  uniform_int_distribution<int> uni1(1000, 1999);

  for (int i = 0; i < 10000; i+=10) {
    int array [1000];
    int n = (sizeof(array)/sizeof(*array));
    bestcase << i << ",";

    // insert
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      array[j] = r;
    }

    clock_t start = clock();
    bestcase << (clock() - start) << ",";
    radixSort(array, n, 4);

  }
  randomcase.close();

  ofstream worstcase("./dataRadix/radixWorstCase.txt");


  int array [] = {225,548,378,169,792,172,296,732};
  radixSort(array, 8, 3);
  for (int i = 0; i < 8; i++) {
    cout << array[i]<< '\n';
  }
  return 0;
}
