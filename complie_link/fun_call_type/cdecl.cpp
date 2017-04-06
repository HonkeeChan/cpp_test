#include <cstdio>
void __cdecl func(int param1, int param2, int param3) {
  int var1 = param1;
  int var2 = param2;
  int var3 = param3;
  printf("%ld\n", long(param1));
  printf("%ld\n", long(param2));
  printf("%ld\n", long(param3));
  printf("----------------\n");
  printf("%ld\n", long(&var1));
  printf("%ld\n", long(&var2));
  printf("%ld\n", long(&var3));
  return ;
}
int main() {
  func(1, 2, 3);
  return 0;
}
