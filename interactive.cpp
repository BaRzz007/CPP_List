#include "interactive.cpp"


class interactive::Context {
	private:
		Linked_list list;
		std::string context;
	public:
		Context(std::string context) : list(new Linked_list), context(context) {}
		void append(std::string item_str) {}
		void insert(std::string item_str, int index) {}
		void push(std::string item_str) {}
		void remove(std::string item_str) {}
		void remove(int index) {}
		void clearList() {}
		void help(std::string func) {}
};
