#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <string>

class Todo_list {
  private:
    class Todo_list_item;
    Todo_list_item *head;
    int count;

  public:
    Todo_list();
    void printList();
    std::string getItem(int index);
    void remove(int index);
    void remove(std::string &todoString);
    void append(std::string new_item);
    void insert(std::string new_item, int index);
    void push(std::string new_item);
};



#endif //TODO_LIST_H
