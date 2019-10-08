#ifndef DIR_H
#define DIR_H

#include <iostream>
#include <string>

class Dir {
   std::string dirname;
   std::string parentname;
public:
   Dir(std::string, std::string);
   std::string getName();
   std::string getParent();
};

#endif // DIR_H
