#include <iostream>
#include <cmath>
#include "Heap.h"
using namespace std;

Heap::Heap(int size) {
  
}

int Heap::getRoot() {
  return heap[0];
}

int Heap::getParent(int index) {
  return floor(index / 2);
}

int Heap::getLeftChild(int index) {
  return index * 2;
}

int Heap::getRightChild(int index) {
  return index * 2 + 1;
}

void Heap::add(int number) {
  cout << "size=" << size << ", last=" << last << endl;
  
  // add number to end
  heap[last] = number;
  
  // update size and last position
  size++;
  last++;

  // sort it up
  sortUp(last);
}

void Heap::remove() {
  // set root to lowest
  heap[0] = heap[last];

  // clear last node and set new last to the parent
  heap[last] = 0;
  last = getParent(last);
  size--;

  // sort it down
  sortDown(0);
}

void Heap::removeAll() {
  while (size > 0) {
    remove();
  }
}

// sort highest values to top
void Heap::sortUp(int index) {
  int value = heap[index];
  int parentIndex = getParent(index);
  int parentValue = heap[getParent(index)];

  // at root
  if (index == 0) return;

  // sort up
  if (parentValue < value) {
    // swap parent and child
    heap[index] = parentValue;
    heap[parentIndex] = value;

    // recursion
    sortUp(parentIndex);
  }
}

void Heap::sortDown(int index) {
  
}

void Heap::print(int pos, int depth) {
  if (getLeftChild(pos) < size) {
    // recursion at this point, return here once nulls are reached
    print(getLeftChild(pos), depth + 1);
  }
}
