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