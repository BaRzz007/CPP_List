#include <iostream>
#include <string>
#include "linked_list.hpp"


int main()
{
  Linked_list market_list; //creates new Linked-List
  
  market_list.append("Buy some tomato"); //adds an item to the end of the list
  market_list.append("Buy fried plantain"); //adds an item to the end of the list
  market_list.append("Get a notepad for study"); //adds an item to the end of the list
  market_list.printList(); //see all the items in the list

  market_list.push("Priority: Restock on toiletories"); //adds an item to the beginning of the list
  market_list.printList();

  market_list.insert("Get a brown bag", 3); //adds an item to the middle of the list at index 3
  market_list.printList();

  market_list.remove(1); //remove node by index
  market_list.remove("Buy some tomato"); //remove node by value
  market_list.clearList(); //clear the linked list

  market_list.remove(0); //attempt to delete item from an empty list returns an error stating that the list is empty
  
  return (0);
}
