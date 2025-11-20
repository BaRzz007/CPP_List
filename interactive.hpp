#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "linked_list.hpp"


class Session {
  public:
    void run();

  private:
    class Context;
    std::unordered_map<std::string, Linked_list> lists;
    void prompt; //while loop lives here
    void input(); //contains the functions the session can execute
    void help(std::string func);
    void createList();
    void deleteList();
};
