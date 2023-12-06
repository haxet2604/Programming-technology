#include "user.h"
#include <iostream>

void User::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Years: " << years << std::endl;
}
