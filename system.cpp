#include "system.h"

System::System() {
	currentFolder = "/";
	path = "/";
};

std::string System::getCurrentFolder() {
	return currentFolder;
}

void System::mkdir(std::string newDir, std::string currentFolder) {
	dirs.push_back(new Dir(newDir, currentFolder));
}

void System::ls() {
	for (auto& d : dirs) {
		if (d->getParent() == currentFolder)
			std::cout << d->getName() << "\t";
	}
	if (!dirs.empty())
		std::cout << std::endl;
}

void System::cd(std::string dirname) {
	this->currentFolder = dirname;
	this->path += dirname + "/";
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
		std::cerr << "Already in root.\n";
	}
}

void System::printPath() {
	std::cout << this->user << this->path + "$ ";
}

bool System::hasChild(std::string dirname) {
	bool help = false;
	for (auto& iter : dirs) {
		if (iter->getParent() == dirname) {
			help = true;
		}
	}
	return help;
}

void System::rm(std::string dirname) {
	if (hasChild(dirname) == true) {
		std::cerr << "failed to remove " << "'" << dirname << "': " << "Directory not empty" << std::endl;
	}
	else if (hasChild(dirname) == false) {
		for (unsigned i = 0; i < dirs.size(); i++) {
			if (dirs[i]->getName() == dirname) {
				dirs.erase(dirs.begin() + i);
			}
		}
	}
}

bool System::isExists(std::string dirname) {
	bool exist = false;
	for (auto& iter : dirs) {
		if (iter->getName() == dirname) {
			exist = true;
		}
	}
	return exist;
}



