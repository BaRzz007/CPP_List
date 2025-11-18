#include <iostream>
#include <string>
#include "linked_list.hpp"

/** This is an internal Node class for the list items stored in the linked-list, thus encapsulating
 *  its implementation.
 *
 *  Member variables of the node class are "value" and "next", which store the value
 *  stored in the node and a pointer to the next node in the list.
 */
class Linked_list::Node {
  public:
    std::string value;
    Node *next;
    Node(std::string item_str) : value(item_str), next(nullptr) {}
//This function returns the value of the node as a string object
    std::string print() {
      return (this->value);
    }
};



/** This is where the definition of the methods for the Linked-list starts
 *  The declaration can be found in the "linked_list.hpp header file
 */

//constructor to the linksed-list
Linked_list::Linked_list() : head(nullptr), count(0) {}

//This function adds a node to the end of the linked-list
void Linked_list::append(std::string item_str)
{
  Node *new_item = new Node(item_str);
  if (!head) //if the list is empty
  {
    head = new_item;
    count++;
    std::cout << "Item added successfully!" << std::endl;
    return;
  }

  Node *last = head;
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = new_item;
  count++;
  std::cout << "Item added successfully!" << std::endl;
  return;
}

//This function adds a node to the beginning of the list
void Linked_list::push(std::string item_str)
{
  Node *new_item = new Node(item_str);
  new_item->next = head;
  head = new_item;
  count++;
  std::cout << "Item added successfully!" << std::endl;
  return;
}

//This function adds a node to a specified index,, so a node can also be added to the middle of the list
void Linked_list::insert(std::string item_str, int index)
{
  Node *current = head;
  if (Linked_list::count < index) {
        std::cout << "Index has exceeded current size of the list" << std::endl; //handle_error.index_exceeded();
        return;
  }
  
  for (int i = 0; i <= index - 1; i++)
      current = current->next;
  
  Node *new_item = new Node(item_str);
  new_item->next = current->next;
  current->next = new_item;
  count++;
  std::cout << "Item added at index " << index << "successfully!" << std::endl;
  return;
}

//This function displays all the items that are in the list
void Linked_list::printList()
{
  if (!head) {
    std::cout << "The list is empty!" << std::endl;
    return;
  }
  Node *current = head;
  int index = 0; //revisit
  while (current != nullptr) {
    std::cout << index << "[ Task " << (index + 1) << ": " << current->print() << " ]" << std::endl;
    current = current->next;
    index++;
  }
}

//This function removes a node from the list by index
void Linked_list::remove(int index)
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
  Node *current = head;
  while (i < index) {
    current = current->next;
    i++;
  }
  current->next = current->next->next;
  delete current->next; //garbage collection
	count--;
  std::cout << "Item deleted successfully" << std::endl;
}

//This function removes an item by value from a linked list
void Linked_list::remove(std::string item_str)
{
  if (!head) {
    std::cout << "Cannot remove from an empty list" << std::endl; //handle_error.emptyList();
    return;
  }

  Node *current = head;
  while (current != nullptr) {
    if (current->value == item_str) {
      delete current->next;
			count--;
      std::cout << "Item deleted successfully" << std::endl;
    }
  }
}

//This function clears the whole list
void Linked_list::clearList()
{
	if (!head) {
		std::cout << "The list is already empty" << std::endl;
	}
	Node *current = head;
	Node *temp;
	while (current != nullptr) {
		temp = current;
		current = current->next;
		delete temp;
		count--;
	}
	std::cout << "The list is now cleared and empty" << std::endl;
}

/* #TODO:
insert(): Done
push(): Done
printAll(): Done
getItem(): postponed
remove(): Done
append(): Done
clearList(): Done
*/



