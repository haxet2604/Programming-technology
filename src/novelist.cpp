#include "novelist.h"
#include <iostream>

Novelist::Novelist(const std::string& name, const std::string& years, const std::string* works, int numWorks, const std::string& biography)
    : numWorks(numWorks), biography(biography) {
    this->name = name;
    this->years = years;
    this->works = new std::string[numWorks];
    for (int i = 0; i < numWorks; ++i) {
        this->works[i] = works[i];
    }
}

Novelist::~Novelist() {
    delete[] works;
}

void Novelist::displayInfo() const {
    User::displayInfo();
    std::cout << "Works:" << std::endl;
    for (int i = 0; i < numWorks; ++i) {
        std::cout << " - " << works[i] << std::endl;
    }
    std::cout << "Biography: " << biography << std::endl;
}
