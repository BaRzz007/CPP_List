#ifndef TODO_H
#define TODO_H

#include <string>

class Todo_list {
private:
  int index;
  std::string todo;

public:
  Todo_list *next;

  Todo_list();
  void printAll();
  std::string getTodo(int index);
  void remove(int index);
  void addItem(std::string &todo);
};

#endif //TODO_H
