#include "system.h"

std::string System::getCurrentFolder(){
    return currentFolder;
}

void System::mkDir(std::string newDir){
    dirs.push_back(new Dir(newDir, currentFolder));
}

void System::ls(){
    for (auto &d : dirs) {
        if(d->getParent() == currentFolder){
            std::cout << d->getName() << " " << d->getParent() << std::endl;
        }
    }
}

void System::cd(std::string dirname){
    this->currentFolder = dirname;
}

void System::cdBack() {
    if (currentFolder != "/"){
        for (auto &d : dirs){
            if (currentFolder == d->getName()){
                currentFolder = d->getParent();
            }
        }
    } else {
        std::cerr << "You are already in a root...\n" << std::endl;
    }
}
