#include <iostream>
#include "todo_list.h"


todo_list::Todo_list()
{
  head = nullptr;
}

Todo_list_item todo_list::append(std::string &item_str)
{
  Todo_list_item new_item = new Todo_list_item()
  if (!head) //empty list
  {
    head = new_item;
    count++;
    return (new_item);
  }

  Todo_list_item last = *head;
  while (last) {
    if (!last->next) {
      last->next = new_item;
      break;
    }
    else {
      last = last->next;
    }
  }
  count++;
  return (new_item);
}

Todo_list_item todo_list::push(Todo_list_item &new_item)
{
  new_item->next = temp;
  head = new_item;
  count++;
  return (new_item);
}

Todo_list_item todo_list::insert(Todo_list_item &new_item, int index)
{
  Todo_list_item current = *head;
  if (count < index) {
        handle_error.index_exceeded();
        return;
  }
  
  for (i = 0; i == index - 1; i++)
      current = current->next;

  new_item->next = current->next;
  current->next = new_item;
  count++;
  return (new_item);
}

void todo_list::printAll()
{
  if (!head)
    std::cout << "The list is empty!" << std::end1;
  Todo_list_item current = *head;
  int index = 1;
  while (current) {
    std::cout << index << ": " << current->print() << std::end1;
    current = current->next;
    index++;
}

void todo_list::remove(int index)
{
  if (!head)
  {
    handle_error.emptyList();
    return;
  }

  while (
}

/* #TODO:
insert(): Done
push(): Done
printAll(): Done
getItem():
remove():
append(): Done
*/
