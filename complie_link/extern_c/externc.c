#include <stdio.h>
#include "example.h"        //注：此处不妥，如果这样编译通不过，换成 extern "C" int add(int , int ); 可以通过


int main(int argc, char* argv[])
{
    　printf("%d\n",add(2,3));
    　return 0;
}
