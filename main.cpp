#include <iostream>
#include <string>
#include "todo_list.h"


int main(int argc, char **argv)
{
  
  Todo_list market_list();
  
  Todo_list_item item1 = market_list.addItem("Buy some tomato");
  Todo_list_item item2 = market_list.addItem("Buy fried plantain");

  market_list.printAll();

  market_list.remove(1);
  
}
