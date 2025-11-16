#include <iostream>
#include <string>
#include "todo_list.h"


int main(int argc, char **argv)
{
  Todo_list market_list;
  
  market_list.append("Buy some tomato");
  market_list.append("Buy fried plantain");
  market_list.append("Get a notepad for study");

  market_list.printAll();
  
}
