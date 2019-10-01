#include "system.h"

std::string System::getCurrentFolder() {
	return currentFolder;
}

void System::mkdir(std::string newDir) {
	dirs.push_back(new Dir(newDir, currentFolder));
}

void System::ls() {
	for (auto& d : dirs) {
		if (d->getParent() == currentFolder)
            std::cout << d->getName() << std::endl;
	}
}

void System::cd(std::string dirname) {
    if(currentFolder !=dirname){
	this->currentFolder = dirname;
    this->path += dirname + "/";}
}

void System::cdBack() {
	if (currentFolder != "/") {
		for (auto& d : dirs) {
			if (currentFolder == d->getName()) {
				path.erase(path.end() - (currentFolder.size() + 1), path.end());
				currentFolder = d->getParent();
			}
		}
	}
	else {
		std::cerr << "Already in root.\n" << std::endl;
	}
}

void System::printPath() {
	std::cout << this->user << this->path + "$ ";
}

bool System::hasChild(std::string dirname){
    bool help=false;
    for(auto &iter : dirs){
       if(iter->getParent()==dirname){
           help=true;
       }
    }
    return help;
}

void System::rm(std::string dirname){
    if(currentFolder != dirname){
        if(hasChild(dirname)==true){
            std::cerr << "Cannot be removed..." << std::endl;
        }
        else if (hasChild(dirname) == false){
            for(unsigned i=0; i<dirs.size();i++){
                if(dirs[i]->getName()== dirname){
                    dirs.erase(dirs.begin()+i);
                }
            }
        }
    }
    else {std::cerr << "rm: cannot remove '" << dirname <<"': Is a directory"  << std::endl; }
}


bool System::isExist(std::string dirname){
    bool exist=false;
    for (auto &iter : dirs){
        if(iter->getName()==dirname){
           exist=true;
        }
    }
    return exist;
}

std::string System::getChild(std::string dirname){
    for(auto &iter : dirs){
        if(iter->getParent()==dirname){
            return iter->getName();
        }
    }
    return "No child found...";
}
void System::rmrf(std::string dirname){
    if(currentFolder != dirname){
        for(auto &iter : dirs){
            while(hasChild(dirname)){
                rmrf(getChild(dirname));
            }
            rm(dirname);
        }
    } else std::cerr << "rm: cannot remove '" << dirname <<"': Is a directory"  << std::endl;
}


