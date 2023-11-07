#include "scifiwriter.h"
#include <iostream>

SciFiWriter::SciFiWriter(const std::string& name, const std::string& years, const std::string* works, int numWorks, bool moviesAdaptation)
    : numWorks(numWorks), moviesAdaptation(moviesAdaptation) {
    this->name = name;
    this->years = years;
    this->works = new std::string[numWorks];
    for (int i = 0; i < numWorks; ++i) {
        this->works[i] = works[i];
    }
}

SciFiWriter::~SciFiWriter() {
    delete[] works;
}

void SciFiWriter::displayInfo() const {
    User::displayInfo();
    std::cout << "Works:" << std::endl;
    for (int i = 0; i < numWorks; ++i) {
        std::cout << " - " << works[i] << std::endl;
    }
    std::cout << "Movies Adaptation: " << (moviesAdaptation ? "Yes" : "No") << std::endl;
}
