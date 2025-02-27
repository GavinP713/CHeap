#include <iostream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include "Heap.h"
using namespace std;

void numbersFromRange(Heap* heap, bool random);
void numbersFromFile(Heap* heap);

int main() {
  Heap* heap = new Heap();
  char input[32];

  //list of commands
  cout << "\"add\" - add numbers to the heap in various ways" << endl;
  cout << "\"remove\" - remove and display top number from heap" << endl;
  cout << "\"remove-all\" - remove all numbers from the heap" << endl;
  cout << "\"print\" - print a tree diagram of the heap" << endl;
  cout << "\"quit\" - quit the program" << endl;
  
  while (true) {
    cin >> input;
    
    if (strcmp(input, "add") == 0) {
      cout << "INPUT TYPE: " << endl;
      cout << "- range" << endl;
      cout << "- file" << endl;
      cout << "- random" << endl;
			    cin >> input;

      if (strcmp(input, "range") == 0) {
	numbersFromRange(heap, false);
      }
      else if (strcmp(input, "random") == 0) {
	numbersFromRange(heap, true);
      }
      else if (strcmp(input, "file") == 0) {
	numbersFromFile(heap);
      }
    }
    else if (strcmp(input, "remove") == 0) {
      heap->remove();
    }
    else if (strcmp(input, "remove-all") == 0) {
      heap->removeAll();
    }
    else if (strcmp(input, "print") == 0) {
      heap->print(1, 0);
    }
    else if (strcmp(input, "quit") == 0) {
      return 1;
    }
    else {
      cout << "unkown command" << endl;
    }
  }
  
  return 1;
}

void numbersFromRange(Heap* heap, bool random) {
  char input[128];

  // ammount of numbers to add
  int range;
  cout << "range (int): ";
  cin >> input;
  range = atoi(input);

  // add numbers
  for (int i = 0; i < range; i++) {
    // manually input
    if (random == false) {
      cout << "number (int): ";
      cin >> input;
      heap->add(atoi(input));
    }
    // add randomized numbers
    else {
      heap->add(rand() % 100);
    }
  }
}

void numbersFromFile(Heap* heap) {
  char input[32];

  // select file
  cout << "!selected files should include only integers seperated by lines!" << endl;
  cout << "File: ";
  cin >> input;

  // find file
  ifstream file(input);
  char line[128];
  
  // read the file
  while (file >> line) {
    heap->add(atoi(line));
  }
}
