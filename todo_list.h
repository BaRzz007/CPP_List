#ifndef TODO_H
#define TODO_H

#include <string>

class Todo_list {
  private:
    Todo_list_item *head;
    int item_count;

  public:
    Todo_list();
    void printList();
    Todo_list_item getItem(int index);
    void remove(int index);
    void remove(std::string &todoString)
    Todo_list_item append(std::string &new_item);
    Todo_list_item insert(std::string &new_item, int index);
    Todo_list_item push(std::string &new_item);
};

class Todo_list_item {
  private:
    std::string item;

  public:
    Todo_list_item(std::string &item_str);
    Todo_list_item *next;
    int index;
    void print();
};

#endif //TODO_H
