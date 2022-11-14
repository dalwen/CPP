#include <iostream>
using namespace std;
#include "PlayGround.hpp"

void FollowPointer() {
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

int main() {
  FollowPointer();
}
