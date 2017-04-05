#include <stdio.h>

int f(){
    printf("f()\n");
}
// int f(int i){
//     printf("f(int)\n");
// }

int main(){
    f();
    f(1);
    return 0;
}