#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  dat.push_back("1");
  dat.push_front("2");
  dat.push_back("3");

  // Display dat values 
  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;

  // Display back and front of dat
  std::cout << dat.back() << std::endl;
  std::cout << dat.front() << std::endl;

  // Remove last and first values of dat
  dat.pop_back();
  dat.pop_front();

  // Display size
  std::cout << dat.size() << std::endl;

}
