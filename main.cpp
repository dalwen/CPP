#include <iostream>
using namespace std;
#include "PlayGround.hpp"



main() {
  int *q;
  int trouble[3];

  trouble[0] = 1;
  q = &trouble[1];
  *q = 2;
  trouble[2] = 3;

  HardToFollow(q, trouble[0], &trouble[2]);
  Unknown(&trouble[0], *q);

  cout << *q << " " << trouble[0] << " " << trouble[2];
}


void Unknown(int *t2, int q) {
  int *temp;

  temp = &q;
  *t2 = *temp + 2;
  q = 7;
}

void HardToFollow(int *q, int t0, int *t2) {
  *q = t0 + *t2;
  *t2 = t0;
  t2 = q;
  q = &t0;
  Unknown(t2, *q);
}