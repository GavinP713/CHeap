#include <iostream>
#include <cmath>
#include "Heap.h"
using namespace std;

int Heap::getRoot() {
  return heap[1];
}

int Heap::getParent(int index) {
  return floor(index / 2);
}

int Heap::getLeft(int index) {
  return index * 2;
}

int Heap::getRight(int index) {
  return index * 2 + 1;
}

void Heap::add(int number) {
  //cout << "size=" << size << ", last=" << last << endl;
  
  // add number to end
  heap[last] = number;

  // sort it up
  sortUp(last);
  
  // update size and last position
  size++;
  last++;
}

void Heap::remove() {
  cout << heap[1] << endl;

  // set root to lowest
  heap[1] = heap[last - 1];

  // clear last node and set new last to the parent
  heap[last] = 0;
  last--;
  size--;

  // sort it down
  sortDown(1);
}

void Heap::removeAll() {
  while (heap[1] != 0) {
    remove();
  }
}

// sort highest values to top
void Heap::sortUp(int pos) {
  if (pos == 1) return; // at root
    
  int value = heap[pos]; // value always zero !!! error
  int parentPos = getParent(pos);
  int parentValue = heap[getParent(pos)];
  
  // sort up
  if (parentValue < value) {
    // swap parent and child
    heap[pos] = parentValue;
    heap[parentPos] = value;

    // repeat
    sortUp(parentPos);
  }
}

void Heap::sortDown(int pos) {
  if (pos > size) return; // reached a leaf

  // convenient references
  int value = heap[pos];
  int leftValue = heap[getLeft(pos)];
  int rightValue = heap[getRight(pos)];
  
  // a child is larger than the current value
  if (leftValue > value || rightValue > value) {
    // swap with left child
    if (leftValue > rightValue) { 
      heap[pos] = leftValue;
      heap[getLeft(pos)] = value;
      sortDown(getLeft(pos));
    }
    // swap with right child
    else { 
      heap[pos] = rightValue;
      heap[getRight(pos)] = value;
      sortDown(getRight(pos));
    }
  }
}

void Heap::print(int pos, int depth) {
  //cout << getRight(pos) << endl;
  //cout << last << endl;

  //  return;
  if (getRight(pos) < last) { // check for null 
    print(getRight(pos), depth + 1);
  }
  
  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  
  cout << heap[pos] << endl;
  
  if (getLeft(pos) < last) { // check for null
    print(getLeft(pos), depth + 1);
  }
}
