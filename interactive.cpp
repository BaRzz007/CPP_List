#include "interactive.hpp"


class Session::Context {
	private:
		Linked_list *list;
		std::string context;
	public:
		Context(std::string context) : list(new Linked_list), context(context) {}
		void append(std::string item_str) {}
		void insert(std::string item_str, int index) {}
		void push(std::string item_str) {}
		void remove(std::string item_str) {}
		void remove(int index) {}
		void clearList() {}
		void printList() {}
		void help(std::string func) {}
};

void Session::run() {
	std::string buffer;
	std::vector<std::string> tokens;
	bool exit = false;
	while (!exit) {
		std::cout << prompt;
		buffer = input();
		tokens = parse(buffer);
		exit = exec(tokens);
	}
}

bool Session::exec(std::vector<std::string> tokens) {
	switch (tokens[0]) {
		case "create":
			std::cout << "create test" << std::endl;
			//createList(token[1]);
			break;
		case "delete":
			std::cout << "delete test" << std::endl;
			//deleteList(token[1]);
			break;
		case "lists":
			std::cout << "lists test" << std::endl;
		    //lists();
		    break;
		case "help":
			std::cout << "help test" << std::endl;
			/*if (token.size() > 1) {
				help(token[1]);
			} else {
				help();
			}*/
			break;
		case "exit":
			for (const auto& [name, context] : this->lists) {
				context.clearList();
			}
			return true;
		default:
		    Context context = get_context(tokens[0]);
			if (context == nullptr) {
				std::cout << "Command does not exit" << std::endl;
			}
		    switch (tokens[1]) {
				case "append":
				    context.append(tokens[2]);
				    break;
				case "push":
				    context.push(tokens[2]);
				    break;
				case "insert":
					int idx = std::stoi(tokens[2]);
				    context.insert(tokens[3], idx);
				    break;
				case "remove":
				    context.remove(tokens[2]); //context should handle datatype conversion to call the right function
				    break;
				case "show_all":
				    context.printList();
				    break;
				default:
					std::cout << tokens[0] << ": " << tokens[1] << ": Unknown Command" << std::endl;
			}
	}
	
	return false;
}

	std::string Session::input() {
		std::string line;
		std::getline(std::cin, line);
		return line;
	}

	std::vector<std::string> Session::parse(std::string buffer) {
		std::vector<std::string> tokens;
		std::size_t pos = 0;
		std::size_t found = pos;

		int i = 0;
		while (found != std::string::npos) {
			found = buffer.substr(pos).find(" ");

			if (buffer.substr(pos)[0] == '"') {
				pos++;
				found = buffer.substr(pos).find("\"");
				tokens[i] = buffer.substr(pos, found);
				pos += found + 2;
				i++;
				if (pos > buffer.length())
					return tokens;
			} else {
				tokens[i] = buffer.substr(pos, found);
				pos += found + 1;
			}
		}
		return tokens;
	}
}
