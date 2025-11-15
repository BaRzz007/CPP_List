#ifndef TODO_H
#define TODO_H

#include <string>

class Todo_list {
private:
  int index = 0;
  std::string todo = NULL;

public:
  Todo_list *next;

  void print_all();
  std::string get_todo(int index);
  void remove(int index);
  void add_item(std::string todo);
}

#endif //TODO_H
