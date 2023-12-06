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

std::string Novelist::getNovelistsInfo() const {
    std::string info = "Name: " + name + "\n";
    info += "Years: " + years + "\n";
    info += "Biography: " + biography + "\n";
    info += "Works:\n";
    for (int i = 0; i < numWorks; ++i) {
        info += "- " + works[i] + "\n";
    }
    return info;
}
