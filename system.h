#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "dir.h"

class System {
	std::vector<Dir*> dirs;
	std::string user = "Domain@Host:";
	std::string currentFolder;
	std::string path;
public:
	System();

	std::string getCurrentFolder();

	void mkdir(std::string, std::string);
	void ls();
	void cd(std::string);
	void cdBack();
	void printPath();
	void rm(std::string);

	bool hasChild(std::string);
	bool isExists(std::string);
};

#endif // SYSTEM_H
