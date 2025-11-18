#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class Linked_list {
  private:
    class Node;
    Node *head;
    int count;

  public:
    Linked_list();
    void printList();
    std::string getItem(int index);
    void remove(int index);
    void remove(std::string &todoString);
    void append(std::string new_item);
    void insert(std::string new_item, int index);
    void push(std::string new_item);
    void clearList();
};



#endif //TODO_LIST_H
