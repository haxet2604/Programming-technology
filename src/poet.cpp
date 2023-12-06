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

std::string Poet::getPoetInfo() const {
    std::string info = "Name: " + name + "\n";
    info += "Years: " + years + "\n";
    info += "Works:\n";
    for (int i = 0; i < numMajorWorks; ++i) {
        info += "- " + this->majorWorks[i] + "\n";
    }
    return info;
}
