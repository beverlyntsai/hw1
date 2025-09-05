/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

// Helper display function
void display(Node* head){
  Node* curr = head;
  while(curr != NULL){
    std::cout << curr->value << std::endl;
    curr = curr->next;
  }
}

int main(int argc, char* argv[])
{
  Node* in = new Node{1, nullptr};
  in->next = new Node{2, nullptr};
  in->next->next = new Node{3, nullptr};
  in->next->next->next = new Node{4, nullptr};

  Node* odds = NULL;
  Node* evens = NULL;

  split(in, odds, evens);

  // Display new linked lists
  std::cout << "Odd list: " << std::endl;
  display(odds);

  std::cout << "Even list: " << std::endl;
  display(evens);
}