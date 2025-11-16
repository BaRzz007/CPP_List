#include <iostream>
#include <string>
#include "todo_list.h"


int main(int argc, char **argv)
{
  Todo_list market_list();
  
  std::string item1 = market_list.append("Buy some tomato");
  std::string item2 = market_list.append("Buy fried plantain");
  std::string item3 = market_list.append("Get a notepad for study");

  market_list.printAll();
  
}
