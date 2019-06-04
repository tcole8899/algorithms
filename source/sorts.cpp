#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int n) {
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < n - 1; ++i){
      swap(&arr[i], &arr[i+1]);
      sorted = false;
    }
  }
}
