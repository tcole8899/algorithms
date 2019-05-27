#include <iostream>

void incriment(int*,int);


int main(){
    int* intarray;
    intarray = new int[10];

    for(int i = 0; i < 10; ++i){
        std::cout << intarray[i] << std::endl;
    }
    
    incriment(intarray, 10);

    for(int i = 0; i < 10; ++i){
        std::cout << intarray[i] << std::endl;
    }

    delete[] intarray;


    return 0;
}

void incriment(int* a, int size){

    for(int i = 0; i < size; ++i){
        a[i]++;
    }
}