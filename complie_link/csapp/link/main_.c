#include <stdio.h>
void swap();
int buf[2] = {1, 2};

int _main(){
	printf("%d\n", buf[0]);
	swap();
	printf("%d\n", buf[0]);
	return 0;
}
