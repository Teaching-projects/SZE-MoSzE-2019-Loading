#include <iostream>
#include "system.h"


int main(int argc, char** argv) {

	System system;
	std::string command;
	std::string dirName;

	while (true) {
		system.printPath();
		std::cin >> command;
		if (command == "ls")
			system.ls();
		else if (command == "mkdir") {
			std::cin >> dirName;
			system.mkdir(dirName);
		}
		else if (command == "cd") {
			std::cin >> dirName;
			if (dirName == "..")
				system.cdBack();
			else system.cd(dirName);
		}
		else if (command == "rm") {
			std::cin >> dirName;
			if (system.isExist(dirName) == true) { system.rm(dirName); }
			else { std::cerr << dirName << ": No such file or directory" << std::endl; }
		}
		else if (command == "quit") return 0;
		else { std::cerr << command << ": command not found" << std::endl; }
	}
}

