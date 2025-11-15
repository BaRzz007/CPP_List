#ifndef TODO_H
#define TODO_H

#include <string>

class Todo_list {
private:
  int index;
  std::string item;

public:
  Todo_list *next;

  Todo_list(std::string &todo);
  void printList();
  void print();
  std::string getItem(int index);
  void remove(int index);
  Todo_list addItem(std::string &todo);
};

#endif //TODO_H
