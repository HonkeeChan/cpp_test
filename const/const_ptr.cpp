#include <iostream>

int main(){
    int i = 1;
    int const*p =&i;
    p++;
    std::cout << "p: "  << *p << std::endl;
    std::cout << "p-1: " << *(p - 1) << std::endl;
}
