#ifndef HEAP_H
#define HEAP_H

class Heap {
 public:
  int size;
  int last;
  
  Heap(int size);

  int getRoot();
  int getParent(int index);
  int getLeftChild(int index);
  int getRightChild(int index);

  void add(int number);
  void remove();
  void removeAll();

  void sortUp(int index);
  void sortDown(int index);

  void print();
 private:
  int heap[100];
};

#endif 
