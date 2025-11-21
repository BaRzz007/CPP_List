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
    void lists(); //prints all contexts (lists) in the session
    Context get_context(std::string cmd);
    bool exec(std::vector<std::string> tokens);
    std::vector<std::string> parse(std::string);
};
