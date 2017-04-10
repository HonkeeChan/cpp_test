#include <stdio.h>

int main(){
    char* str[3] = {"hello", "world", "hi"};
    char *p = str[0];
    for(int i = 0; i < 20; ++i){
        printf("%c ", *p++);
    }
}
