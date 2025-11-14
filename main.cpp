#include <iostream>
#include "list_obj.h"


int main(int argc, char **argv)
{
  my_list todo_list = new my_list;

  list_item item = new list_tem;
  list_item item2 = new list_item;
  
  todo_list.add_item(item);
  todo_list.add_item(item2);

  todo_list.print_all();

  todo_list.remove(1);

  delete list_item;
  delete todo_list;
  
}
