/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // Create base case and check to see if in is null
  if(in == NULL){
    // Set odds and evens linked list to null
    odds = NULL;
    evens = NULL;
    return;
  }

  // Create current pointer to walk through the code instead of in
  Node* curr = in;
  // Move in to next
  in = in->next;
  // Create recursive case
  split(in, odds, evens);

  // End the new linked list with null
  curr->next = NULL;

  // Check to see if value is odd
  if(curr->value % 2 == 1){
    // Update current pointer to the head of odds linked list
    curr->next = odds;
    // Update odds pointer to point to current, the new head
    odds = curr;
  }
  // Check to see if value is even
  else{
    // Update current pointer to the head of evens linked list
    curr->next = evens;
    // Update evens pointer to point to current, the new head
    evens = curr;
  }
}

/* If you needed a helper function, write it here */
