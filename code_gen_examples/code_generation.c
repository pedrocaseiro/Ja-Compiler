#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int h;

int main(int argc, char* argv[]){
  int l;
  double t;
  bool b;
  t = 4.5;
  b =true;
  l = 5;
  printf("%d\n", l);
  printf("%16E\n", t);
  printf("%d\n", b);

  return 0;
}
