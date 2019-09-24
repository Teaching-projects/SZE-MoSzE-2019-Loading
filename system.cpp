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
    for (auto &d : dirs){
        if (currentFolder == d->getName() && currentFolder != "/"){
            currentFolder = d->getParent();
        }
    }
}
