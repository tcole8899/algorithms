#include "classes.hpp"


String::String(){
    array = new char[1];
    array[0] = '\0';
};

String::String(const char* a){
    unsigned int length;
    for(length = 0; a[length]; ++length);

    array = new char[length+1];

    for(int i = 0; i <= length; ++i){
                array[i] = a[i];
            }
};

String::~String(){
    delete[] array;
};

unsigned int String::length(){
    unsigned int result;
    for(result = 0; this->array[result]; ++result);
    this->length = result;
    return this->length;
};

void String::reverse(){

};

void String::append(const char a){
    char* new_array = new char[this->length + 1];
    for(int i = 0; array[i]; ++i){
        new_array[i] = array[i];
    }
    delete[] array;
    new_array[this->length++] = a;
    new_array[this->length] = '\0';
    this->array = new_array;

};


