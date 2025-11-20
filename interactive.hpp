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
    std::unordered_map<std::string, Context> lists;
    std::string prompt = "=> "; //while loop lives here
    std::string input(); //contains the functions the session can execute
    void help(std::string func=nullptr);
    void createList(std::string list);
    void deleteList(Linked_list list);
    void start_context(Context context);
};
