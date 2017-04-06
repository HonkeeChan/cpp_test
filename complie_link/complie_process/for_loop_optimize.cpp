#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;
    for(; i < 1000; ++i){
	for(; j < 1000; ++j){
           for(; k < 1000; ++k){
	       sum += 1;
           }
	}
    }
    printf("sum %d", sum);
    return 0;
}
