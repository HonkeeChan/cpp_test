#include <iostream>

using namespace std;
void printMemory(void* p);
char tb[] = {'0', '1', '2', '3', '4',
             '5', '6', '7', '8', '9',
             'A', 'B', 'C', 'D', 'E', 'F'
            };
int main(){
    int* p =  new int[10];
    for(int i = 0; i < 20; ++i){
        p[i] = i;
    }
    for(int i = 0; i < 20 ; ++i){
        printMemory(p + i * 2);
    }
    
}

void printMemory(void* p){
    char* pc = (char*)p;
    int high, low;
    for(int i = 0; i < 8; ++i){
        unsigned char uc = *((unsigned char*)p+i);
        high = uc >> 4;
        low = uc & 0x0F;
        cout << tb[high] << tb[low] << " ";
    }
    cout << endl;
}
