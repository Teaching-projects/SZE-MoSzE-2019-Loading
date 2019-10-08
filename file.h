#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>

class File{
   std::string name;
   std::string parent;
public:
   File(std::string, std::string);
   std::string getName();
   std::string getParent();
};

#endif // FILE_H
