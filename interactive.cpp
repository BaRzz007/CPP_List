#include "interactive.cpp"


class Session::Context {
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

Session::run() {
	std::string buffer;
	vector<std::string> tokens;
	bool exit = false;
	while (!exit) {
		std::cout << prompt << ends;
		buffer = input();
		tokens = parse(buffer);
		exit = exec(tokens);
	}

	bool Session::exec(std::vector<std::string> token) {
		switch (token[0]) {
			case “create”:
			    createList(token[1]);
			    break;
			case “delete”:
			    deleteList(token[1]);
			    break;
			case “lists”:
			    lists();
			    break;
			default:
			    Context context = get_context(token[0]);
				if (context == nullptr) {
					std::cout << “Command does not exit” << std::end;
				}
			    switch (token[1]) {
					case ”append”:
					    context.append(token[2]);
					    break;
					case “push”:
					    context.push(token[2]);
					    break;
					case “insert”:
					    context.insert(token[2], token[3]);
					    break;
					case “remove”:
					    context.remove(token[2]); //context should check and call the right function
					    break;
					case “show_all”:
					    context.printList();
					    break;
				}
		}
	}
}
