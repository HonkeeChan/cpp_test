#include <stdio.h>

struct S1{
  int i;
  char c;
  int j;
}S1;
struct S2{
  int i;
  int j;
  char c;
}S2;

int main(){
  printf("sizeof s1 %d\n", sizeof(S1));
  printf("sizeof s2 %d\n", sizeof(S2));
  return 0;    
}
