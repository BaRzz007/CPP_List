#include <iostream>
#include <string>
#include "todo_list.h"


int main(int argc, char **argv)
{
  
  TodoList market_list = new TodoList;

  std:string item = "Buy some tomato";
  std:string item2 = "Buy fried plantain";
  
  todo_list.addItem(item);
  todo_list.addItem(item2);

  todo_list.printAll();

  todo_list.remove(1);

  delete list_item;
  delete todo_list;
  
}
