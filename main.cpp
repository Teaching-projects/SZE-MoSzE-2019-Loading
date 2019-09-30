#include <iostream>
#include "system.h"


int main(int argc, char** argv) {

    System system;
    std::string command;
    std::string dirName;

    do {
        system.printPath();
        std::cin >> command;

        if (command == "ls"){ system.ls(); }
        else if (command == "mkdir") { std::cin >> dirName; system.mkdir(dirName); }
        else if (command == "cd") {
            std::cin >> dirName;
            if (dirName == ".."){
                system.cdBack();
            } else { system.cd(dirName);}
        } else { std::cerr << "Command not found..." << std::endl; }
    } while(command != "quit");
    return 0;
}

