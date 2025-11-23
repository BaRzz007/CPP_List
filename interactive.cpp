#include "interactive.hpp"
#include <sstream>

Session::Context::Context(std::string context_name) : list(std::make_unique<Linked_list>()), context_name(context_name) {}
void Session::Context::append(std::string item_str) { list->append(item_str); }
void Session::Context::insert(std::string item_str, int index) { list->insert(item_str, index); }
void Session::Context::push(std::string item_str) { list->push(item_str); }
void Session::Context::remove(std::string item_str) { list->remove(item_str); }
void Session::Context::remove(int index) { list->remove(index); }
void Session::Context::clearList() { list->clearList(); }
void Session::Context::printList() { list->printList(); }

void Session::run() {
	std::string buffer;
	std::vector<std::string> tokens;
	while (true) {
		std::cout << prompt;
		buffer = input();
		tokens = parse(buffer);
		if (exec(tokens)) {
			break;
		}
	}
}

bool Session::exec(std::vector<std::string> tokens) {

	if (tokens.empty()) {
		return false;
	}

	std::string command = tokens[0];

	if (command == "create") {
		if (tokens.size() > 1) createList(tokens[1]);
		else std::cout << "Usage: create <list_name>" << std::endl;
	} else if (command == "delete") {
		// Not implemented
		std::cout << "delete test" << std::endl;
	} else if (command == "lists") {
		showAll();
	} else if (command == "help") {
		help(tokens.size() > 1 ? tokens[1] : "");
	} else if (command == "exit") {
		for (auto& pair : this->lists) {
			pair.second.clearList();
		}
		return true;
	} else {
		auto it = lists.find(command);
		if (it == lists.end()) {
			std::cout << "List '" << command << "' not found." << std::endl;
			return false;
		}

		Context& context = it->second;
		if (tokens.size() < 2) {
			std::cout << "No command provided for list '" << command << "'" << std::endl;
			return false;
		}

		std::string list_cmd = tokens[1];
		if (list_cmd == "append") {
			if (tokens.size() > 2) context.append(tokens[2]);
			else std::cout << "Usage: " << command << " append <item>" << std::endl;
		} else if (list_cmd == "push") {
			if (tokens.size() > 2) context.push(tokens[2]);
			else std::cout << "Usage: " << command << " push <item>" << std::endl;
		} else if (list_cmd == "insert") {
			if (tokens.size() > 3) {
				try {
					int idx = std::stoi(tokens[2]);
					context.insert(tokens[3], idx);
				} catch (const std::invalid_argument& ia) {
					std::cout << "Invalid index provided for insert." << std::endl;
				}
			} else {
				std::cout << "Usage: " << command << " insert <index> <item>" << std::endl;
			}
		} else if (list_cmd == "remove") {
			if (tokens.size() > 2) {
				try {
					int idx = std::stoi(tokens[2]);
					context.remove(idx);
				} catch (const std::invalid_argument& ia) {
					context.remove(tokens[2]);
				}
			} else {
				std::cout << "Usage: " << command << " remove <index_or_item>" << std::endl;
			}
		} else if (list_cmd == "show_all") {
			context.printList();
		} else {
			std::cout << command << ": " << list_cmd << ": Unknown Command" << std::endl;
		}
	}
	return false;
}

void Session::createList(std::string list_name) {
	if (lists.find(list_name) == lists.end()) {
		lists.emplace(list_name, Context(list_name));
		std::cout << "List '" << list_name << "' created." << std::endl;
	} else {
		std::cout << "List '" << list_name << "' already exists." << std::endl;
	}
}

void Session::showAll() {
	if (lists.empty()) {
		std::cout << "No lists have been created." << std::endl;
		return;
	}
	std::cout << "Available lists:" << std::endl;
	for (const auto& pair : lists) {
		std::cout << "- " << pair.first << std::endl;
	}
}

void Session::help(std::string func) {
	std::cout << "Interactive Session Help:" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "  create <list_name>    - Creates a new list." << std::endl;
	std::cout << "  lists                 - Shows all created lists." << std::endl;
	std::cout << "  <list_name> <command> - Executes a command on a list." << std::endl;
	std::cout << "    append <item>" << std::endl;
	std::cout << "    push <item>" << std::endl;
	std::cout << "    insert <index> <item>" << std::endl;
	std::cout << "    remove <index_or_item>" << std::endl;
	std::cout << "    show_all" << std::endl;
	std::cout << "  help                  - Shows this help message." << std::endl;
	std::cout << "  exit                  - Exits the interactive session." << std::endl;
}

std::string Session::input() {
	std::string line;
	std::getline(std::cin, line);
	return line;
}

std::vector<std::string> Session::parse(std::string buffer) {
	std::vector<std::string> tokens;
	std::stringstream ss(buffer);
	std::string token;
	char quote = '\0';

	while (ss >> std::ws) { // consume leading whitespace
		if (ss.peek() == '\"' || ss.peek() == '\'') {
			quote = ss.get();
			std::getline(ss, token, quote);
		} else {
			ss >> token;
		}
		tokens.push_back(token);
	}
	return tokens;
}
