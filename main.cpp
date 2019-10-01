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
			if (!system.isExists(dirName))
				system.mkdir(dirName, system.getCurrentFolder());
			else std::cerr << command << ": " << "cannot create directory" << " '" << dirName << "': File exist" << std::endl;
		}
		else if (command == "cd") {
			std::cin >> dirName;
			if (dirName == "..")
				system.cdBack();
			else {
				if (!system.isExists(dirName))
					std::cerr << command << ": " << dirName << ": " "No such file or directory" << std::endl;
				else
					system.cd(dirName);
			}
		}
		else if (command == "rm") {
			std::cin >> dirName;
			if (system.isExists(dirName) == true)
				system.rm(dirName);
			else
				std::cerr << command << ": " << "cannot remove" << " '" << dirName << "': " << "No such file or directory" << std::endl;
		}
		else if (command == "quit") return 0;
		else { std::cerr << command << ": command not found" << std::endl; }
	}
}

