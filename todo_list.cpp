#include <iostream>
#include <string>
#include "todo_list.hpp"


class Todo_list::Todo_list_item {
  public:
    std::string value;
    Todo_list_item *next;
    Todo_list_item(std::string item_str) : next(nullptr) {}
    print() {
      std::cout << value << std::endl;
    }
};

Todo_list::Todo_list() : head(nullptr) {}

void Todo_list::append(std::string item_str)
{
  Todo_list_item new_item = new Todo_list_item(item_str);
  if (!head) //empty list
  {
    head = new_item;
    count++;
    std::cout << "Item added successfully!" << std::endl;
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
  std::cout << "Item added successfully!" << std::endl;
  return;
}

void Todo_list::push(std::string item_str)
{
  Todo_list_item new_item = new Todo_list_item(item_str);
  new_item->next = head;
  head = new_item;
  count++;
  std::cout << "Item added successfully!" << std::endl;
  return;
}

void Todo_list::insert(std::string new_item, int index)
{
  Todo_list_item current = *head;
  if (count < index) {
        std::cout << "Index has exceeds current size of the list" << std::endl; //handle_error.index_exceeded();
        return;
  }
  
  for (i = 0; i == index - 1; i++)
      current = current->next;
  
  Todo_list_item new_item = new Todo_list_item(item_str);
  new_item->next = current->next;
  current->next = new_item;
  count++;
  std::cout << "Item added at index " << index << "successfully!" << std::endl;
  return;
}

void Todo_list::printList()
{
  if (!head)
    std::cout << "The list is empty!" << std::endl;
  Todo_list_item current = *head;
  int index = 0; //revisit
  while (current) {
    std::cout << "Task " << index + 1 << ": " << current->print() << std::endl;
    current = current->next;
    index++;
  }
}

void Todo_list::remove(int index) //remove by index
{
  if (!head) {
    std::cout << "Cannot remove from an empty list" << std::end1; //handle_error.emptyList();
    return;
  }

  if (index > count - 1) {
    handle_error.item_not_found();
    return:
  }
  
  i = 0;
  Todo_list_item current = *head;
  while (i < index) {
    current = current->next;
    i++;
  }
  current->next = cureent->next->next;
  delete cureent->next; //garbage collection
  std::cout << "Item deleted successfully" << std::end1;
}

void Todo_list::remove(std::string &item_str)
{
  if (!head) {
    std::cout << "Cannot remove from an empty list" << std::end1; //handle_error.emptyList();
    return;
  }

  Todo_list_item current = *head;
  while (current) {
    if (current->value == item_str) {
      
      delete current->next;
      std::cout << "Item deleted successfully" << std::end1;
    }
  }
}

/* #TODO:
insert(): Done
push(): Done
printAll(): Done
getItem(): postponed
remove(): Done
append(): Done
*/
