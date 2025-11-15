#include <iostream>
#include <string>
#include "todo_list.h"


int main(int argc, char **argv)
{
  
  TodoList market_list();

  std:string item = "Buy some tomato";
  std:string item2 = "Buy fried plantain";
  
  market_list.addItem(item);
  market_list.addItem(item2);

  market_list.printAll();

  market_list.remove(1);
  
}
