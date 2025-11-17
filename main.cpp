#include <iostream>
#include <string>
#include <stdio.h>
#include "todo_list.hpp"


int main()
{
  printf("Good old printf");
  std::cout << "first line" << std::endl;
  Todo_list market_list;
  market_list.append("Buy some tomato");
  market_list.append("Buy fried plantain");
  market_list.append("Get a notepad for study");

  market_list.printList();

  std::cout << "I got here" << std::endl;

  return (0);
}
