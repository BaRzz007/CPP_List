#include <iostream>
#include <string>
#include "linked_list.hpp"


int main()
{
  Linked_list market_list; //creates new Linked-List
	Linked_list course_list;

	std::cout << "Attempting to add first test dataset" << std::endl;
	std::string data_set[] = {
				"Tomato",
				"Plantain",
				"Toiletories",
				"Brown bag",
				"Laptop",
				"HDMI cable",
				"SSD for PC",
				"Birthday cake for Mum"
};
	int data_set_length = sizeof(data_set) / sizeof(data_set[0]);
	for (int i = 0; i < data_set_length; i++) {
		market_list.append(data_set[i]);
	}
	std::cout << "first test dataset added successfully\n" << std::endl;
	market_list.printList(); //see all items in the list
	std::cout << std::endl;
  
  market_list.insert("New Item @ 5 -> Keyboard", 5); //insert an item to index 5 of the list
  market_list.printList(); //see all the items in the list
	std::cout << std::endl;

  market_list.push("Priority: Restock on Munchit :-)"); //adds an item to the beginning of the list
  market_list.printList();
  std::cout << std::endl;

  market_list.remove(3); //remove node by index
  market_list.printList();
  std::cout << "" << std::endl;

  market_list.remove("Plantain"); //remove node by value
	market_list.printList();
	std::cout << std::endl;
	
  market_list.clearList(); //clear the linked list

  market_list.remove(0); //attempt to delete item from an empty list returns an error stating that the list is empty
	std::cout << std:endl;

	std::cout << "Begin testing with second dataset..." << std::endl;
	std::string data_set_2[] = {
				"Introduction to programming II",
				"Philosophy",
				"Mathematics",
				"Basic Logic",
				"Social Studies",
				"System Analysis and Design"
		};
	data_set_length = sizeof(data_set_2) / sizeof(data_set_2[0]);
	for (int i = 0; i < data_set_length; i++) {
		course_list.append(data_set_2[i]);
	}
	std::cout << "second test dataset added successfully\n" << std::endl;
	course_list.printList(); //see all items in the list
	std::cout << std::endl;

	course_list.insert("New Item @ 5 -> Keyboard", 5); //insert an item to index 5 of the list
  course_list.printList(); //see all the items in the list
	std::cout << std::endl;

	course_list.remove("Social Studies");
	course_list.printList(); //see all items in the list
	std::cout << std::endl;

	course_list.clearList();
	course_list.printList();
  
  return (0);
}




