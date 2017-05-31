#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
  int u = 2;
  int y = 4;

  double r = 2.5;
  double p = 1.5;

  printf("%d", u>=y);
  printf("%d", r>=y);
  printf("%d", y>=r);
  printf("%d", p>=r);
  return 0;
}
