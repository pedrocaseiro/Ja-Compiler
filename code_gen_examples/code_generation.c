#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int h;

int main(int argc, char* argv[]){
  int l;
  int y;
  double t;
  bool b;
  char* u = "daniel";
  t = 4.4;
  b =true;
  l = 5;
  printf("%d\n", l);
  printf("%.16E\n", t);
  printf("true\n");
  printf("false\n");
  printf("%s\n", u);
  printf("sfasf\n");
  printf("ola\rola\fola\tola\\ola\\\\ola\n");

  return 0;
}
