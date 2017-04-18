#include <iostream>
#include <stdexcept>

using namespace std;

int* invest(int d, int n){
  int* I = (int*) malloc(sizeof(int)*n);
  int f [n];
  int r [n][10];
  int R [11];

  for (int k = 10; k > 1; k--) {
    int q = 1;
    for (int i = 1; i < n; i++) {
      if (r[i][k] > r[q][k]) {
        q = i;
      }
    }
    if (R[k+1] + d*r[I[k+1]][k] - f[1] > R[k+1] + d*r[q][k] - f[2]) {
      R[k] = R[k+1] + d*r[I[k+1]][k] - f[1];
      I[k] = I[k+1];
    } else {
      R[k] = R[k + 1] + d*r[q][k] - f[2];
      I[k] = q;
    }
  }
  return I;
}

int main() {
  invest(10000, 10);
  return 0;
}
