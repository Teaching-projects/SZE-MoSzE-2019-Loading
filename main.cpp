#include <iostream>
#include "system.h"


int main(int argc, char** argv) {

    System s;
    s.mkDir("Auto");
    s.ls();
    s.cd("Auto");
    s.mkDir("Audi");
    s.mkDir("Seat");
    s.ls();
    s.cdBack();
    s.ls();
    return 0;
}

