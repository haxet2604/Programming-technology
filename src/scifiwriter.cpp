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

std::string SciFiWriter::getScifiwriterInfo() const {
    std::string info = "Name: " + name + "\n";
    info += "Years: " + years + "\n";
    info += "Works:\n";
    for (int i = 0; i < this->numWorks; ++i) {
        info += "- " + this->works[i] + "\n";
    }
    return info;
}
