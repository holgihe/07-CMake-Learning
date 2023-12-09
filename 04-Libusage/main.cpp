#include <iostream>
#include <string>
#include "../include/libdemo.h"


int main (int argc, char** argv) {
    int sum = libdemo::add(std::stoi(argv[1]), std::stoi(argv[2]));
    std::cout << "Sum =  " << sum << std::endl;
    return 0;
}