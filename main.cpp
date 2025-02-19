#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
  Heap* heap = new Heap(100);

  heap->add(4);
  heap->add(10);
  heap->add(2);
  heap->print();
  
  return 1;
}
