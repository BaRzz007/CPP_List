#include <iostream>
#include <string>
#include "todo_list.hpp"


class Todo_list::Todo_list_item {
  public:
    std::string value;
    Todo_list_item *next;
    Todo_list_item(std::string item_str) : value(item_str), next(nullptr) {}
    std::string print() {
      return (this->value);
    }
};

Todo_list::Todo_list() : head(nullptr), count(0) {}

void Todo_list::append(std::string item_str)
{
  Todo_list_item *new_item = new Todo_list_item(item_str);
  if (!head) //empty list
  {
    head = new_item;
    Todo_list::count++;
    std::cout << "Item added successfully!" << std::endl;
    return;
  }

  Todo_list_item *last = head;
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = new_item;
  Todo_list::count++;
  std::cout << "Item added successfully!" << std::endl;
  return;
}

void Todo_list::push(std::string item_str)
{
  Todo_list_item *new_item = new Todo_list_item(item_str);
  new_item->next = head;
  head = new_item;
  Todo_list::count++;
  std::cout << "Item added successfully!" << std::endl;
  return;
}

void Todo_list::insert(std::string item_str, int index)
{
  Todo_list_item *current = head;
  if (Todo_list::count < index) {
        std::cout << "Index has exceeded current size of the list" << std::endl; //handle_error.index_exceeded();
        return;
  }
  
  for (int i = 0; i == index - 1; i++)
      current = current->next;
  
  Todo_list_item *new_item = new Todo_list_item(item_str);
  new_item->next = current->next;
  current->next = new_item;
  Todo_list::count++;
  std::cout << "Item added at index " << index << "successfully!" << std::endl;
  return;
}

void Todo_list::printList()
{
  if (!head) {
    std::cout << "The list is empty!" << std::endl;
    return;
  }
  Todo_list_item *current = head;
  int index = 0; //revisit
  while (current != nullptr) {
    std::cout << "Task " << (index + 1) << ": " << current->print() << std::endl;
    current = current->next;
    index++;
  }
}

void Todo_list::remove(int index)
{
  if (!head) {
    std::cout << "Cannot remove from an empty list" << std::endl; //handle_error.emptyList()
    return;
  }

  if (index > count - 1) {
	  std::cout << "Index exceeds available items in the list" << std::endl; //handle_error.item_not_found()
	  return;
  }
  
  int i = 0;
  Todo_list_item *current = head;
  while (i < index) {
    current = current->next;
    i++;
  }
  current->next = current->next->next;
  delete current->next; //garbage collection
	Todo_list::count--;
  std::cout << "Item deleted successfully" << std::endl;
}

void Todo_list::remove(std::string &item_str)
{
  if (!head) {
    std::cout << "Cannot remove from an empty list" << std::endl; //handle_error.emptyList();
    return;
  }

  Todo_list_item *current = head;
  while (current != nullptr) {
    if (current->value == item_str) {
      
      delete current->next;
			Todo_list::count--;
      std::cout << "Item deleted successfully" << std::endl;
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
