#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>
#include <stdio.h>
#include "linkedlist.h"

using namespace std;

void insetionSort(vector<float> &a){
  for (int i = 0; i < abs(a.size()); i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      float k = a[j-1];
      a[j-1] = a[j];
      a[j] = k;
      j--;
    }
  }
}

void bucketSort(float toBeSorted[], int lengthOfArray){
  vector<float> b [lengthOfArray];
  int counter = 0;

  for (int i = 0; i < lengthOfArray; i++){
    int index = (int) floor(lengthOfArray*toBeSorted[i]);
    b[index].push_back(toBeSorted[i]);
  }
  for (int i = 0; i < lengthOfArray; i++){
    if(!b[i].empty()){
      insetionSort(b[i]);
    }
  }
  for (int i = 0; i < lengthOfArray; i++){
    for(int j = 0; j < abs(b[i].size()); j++){
      toBeSorted[counter] = b[i].at(j);
      counter++;
    }
  }
}

int main() {
  /*ofstream worstcase("./dataRadix/bucketWorstCase.txt");
  float worstcase = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.1));
  ofstream averagecase("./dataRadix/bucketAverageCase.txt");
  float averagecase = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.99999));
  ofstream bestcase("./dataRadix/bucketBestCase.txt");
  float bestcase = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.99999));*/


  float array [] = {.78, .17, .39, .26, .72, .94, .21, .12, .23, .68};
  bucketSort(array, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i]<< '\n';
  }
  return 0;
}
