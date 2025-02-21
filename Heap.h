#ifndef HEAP_H
#define HEAP_H

class Heap {
 public:
  int size;
  int last = 1;
  
  Heap(int _maxSize);

  int getRoot();
  int getParent(int index);
  int getLeft(int index);
  int getRight(int index);

  void add(int number);
  void remove();
  void removeAll();

  void sortUp(int index);
  void sortDown(int index);

  void print(int pos, int depth);
 private:
  int heap[101];
};

#endif 
