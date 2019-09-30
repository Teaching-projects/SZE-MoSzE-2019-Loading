#include "system.h"

std::string System::getCurrentFolder(){
    return currentFolder;
}

void System::mkdir(std::string newDir){
    dirs.push_back(new Dir(newDir, currentFolder));
}

void System::ls(){
    for (auto &d : dirs) {
        if(d->getParent() == currentFolder){
            std::cout << d->getName() << std::endl;
        }
    }
}

void System::cd(std::string dirname){
    this->currentFolder = dirname;
    this->path += dirname + "/";
}

void System::cdBack() {
    if (currentFolder != "/"){
        for (auto &d : dirs){
            if (currentFolder == d->getName()){
                path.erase(path.end() - (currentFolder.size() + 1), path.end());
                currentFolder = d->getParent();
            }
        }
    } else {
        std::cerr << "You are already in a root...\n" << std::endl;
    }
}

void System::printPath() {
    std::cout << this->user << this->path;
}
