#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
  Heap* heap = new Heap(100);

  heap->print();
  
  return 1;
}
