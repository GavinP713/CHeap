#include <iostream>
#include <iostream>
#include <cstring>
#include "Heap.h"
using namespace std;

void numbersFromRange(Heap* heap);
void numbersFromFile(Heap* heap);

int main() {
  Heap* heap = new Heap(100);
  char input[32];
  
  cin >> input;
  
  if (strcmp(input, "add")) {
    cout << "INPUT TYPE: " << endl;
    cout << "range" << endl;
    cout << "OR" << endl;
    cout << "file"
    cin >> input;

    if (strcmp(input, "range")) {
      numbersFromRange(heap);
    }
    else if (strcmp(input, "file")) {
      numbersFromRange(heap);
    }
  }
  else if (strcmp(input, "addfile")) {
  }
  else if (strcmp(input, "remove")) {
  }
  else if (strcmp(input, "print")) {
  }
  else if (strcmp(input, "quit")) {
  }
  else {
    cout << "unkown command" << endl;
  }
  
  return 1;
}

void numbersFromRange(Heap* heap) {
  char input[128];

  // ammount of numbers to add
  int range;
  cout << "range (int): "; cin >> input;
  range = atoi(input);

  // add numbers
  for (int i = 0; i < range; i++) {
    cout << "number (int): "; cin >> input;
    heap->add(atoi(input));
  }
}

void numbersFromFile(Heap* heap) {

}
