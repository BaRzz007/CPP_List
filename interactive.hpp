#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "linked_list.hpp"


class Session {
public:
  void run();

private:
  class Context {
  public:
    Context(std::string context_name);
    void append(std::string item_str);
    void insert(std::string item_str, int index);
    void push(std::string item_str);
    void remove(std::string item_str);
    void remove(int index);
    void clearList();
    void printList();

  private:
    std::unique_ptr<Linked_list> list;
    std::string context_name;
  };
  std::unordered_map<std::string, Context> lists;
  std::string prompt = "=> ";
  std::string input();
  void help(std::string func = "");
  void createList(std::string list);
  void showAll(); //prints all contexts (lists) in the session
  bool exec(std::vector<std::string> tokens);
  std::vector<std::string> parse(std::string);
};

#endif //INTERACTIVE_H
