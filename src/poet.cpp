#include "poet.h"
#include <iostream>

Poet::Poet(const std::string& name, const std::string& years, const std::string* majorWorks, int numMajorWorks)
    : numMajorWorks(numMajorWorks) {
    this->name = name;
    this->years = years;
    this->majorWorks = new std::string[numMajorWorks];
    for (int i = 0; i < numMajorWorks; ++i) {
        this->majorWorks[i] = majorWorks[i];
    }
}

Poet::~Poet() {
    delete[] majorWorks;
}

void Poet::displayInfo() const {
    User::displayInfo();
    std::cout << "Major Works:" << std::endl;
    for (int i = 0; i < numMajorWorks; ++i) {
        std::cout << " - " << majorWorks[i] << std::endl;
    }
}
