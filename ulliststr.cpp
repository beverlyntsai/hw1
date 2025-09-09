#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// Push back function
void ULListStr::push_back(const std::string& val)
{
  // If Item has room
  if(head_ != nullptr && tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }

  // Create new Item and add val to the first index
  else{
    Item* item = new Item();
    item->val[0] = val;
    item->first = 0;
    item->last = 1;

    // If empty Item
    if(head_ == nullptr){
      head_ = item; 
    }

    // If current Item is full
    else{
      item->prev = tail_;
      tail_->next = item;
    }

    // Assign tail to new Item
    tail_ = item;
  }
  
  //Increment size
  size_++;
}

// Push front function
void ULListStr::push_front(const std::string& val){
  // If Item has room
  if(head_ != nullptr && head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;
  }

  // Create new Item and add val to the last index
  else{
    Item* item = new Item();
    item->val[ARRSIZE-1] = val;
    item->first = ARRSIZE-1;
    item->last = ARRSIZE;

    // If empty Item
    if(head_ == nullptr){
      tail_ = item;
    }

    // If current Item is full
    else{
      item->next = head_;
      head_->prev = item;
    }

    // Assign head to new Item
    head_ = item;
  }

  //Increment size
  size_++;
}

// Pop back function
void ULListStr::pop_back(){
  // Check if Item is empty
  if(head_ == nullptr){
    return;
  }

  // Move tail pointer to before last element
  tail_->last--;

  // If Item is now empty after removal
  if(tail_->last == tail_->first){
    // Store Item to delete
    Item* toDelete = tail_;

    // If this is the only Item
    if(tail_->prev == nullptr){
      tail_ = nullptr;
      head_ = nullptr;
    }
    // If there are more than this Item
    else{
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }

    //Deallocate Item
    delete toDelete;

  }
  // Decrement size
  size_--;
}

// Pop front function
void ULListStr::pop_front(){
  // Check if Item is empty
  if(head_ == nullptr){
    return;
  }

  // Move head pointer pass first element
  head_->first++;

  // If Item is now empty after removal
  if(head_->first == head_->last){
    // Store Item to delete
    Item* toDelete = head_;

    // If this is the only Item
    if(head_->next == nullptr){
      head_ = nullptr;
      tail_ = nullptr;
    }
    // If there are more than this Item
    else{
      head_ = head_->next;
      head_->prev = nullptr;
    }

    // Deallocate Item
    delete toDelete;
  }

  // Decrement size
  size_--;
}

// Back function
std::string const & ULListStr::back() const{
  // Return the last element in the last Item
  return tail_->val[tail_->last-1];
}

// Front function
std::string const & ULListStr::front() const{
  // Return the first element in the first Item
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  // If location is greater than size, out of bounds
  if(loc >= size_){
    return nullptr;
  }

  // Create new pointer to move through
  Item *curr = head_;
  // Create index tracker
  int currIndex = 0;

  // Loop through Items
  while(curr != nullptr){
    // Calculate size of each Item
    int itemSize = curr->last - curr->first;

    // Check if loc is in this Item
    if(itemSize + currIndex > loc){
      // Store the found index for loc
      int foundIndex = curr->first + loc - currIndex;
      // Return pointer to a string based on the found index
      return &(curr->val[foundIndex]);
    }

    // Move pointer to next Item
    curr = curr->next;
    // Move index tracker to next Item
    currIndex += itemSize;
  }

  return nullptr;

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
