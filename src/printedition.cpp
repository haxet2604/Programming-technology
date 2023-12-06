#include "PrintEdition.h"
#include <iostream>

PrintEdition::PrintEdition(const std::string& name) : name(name), poets(nullptr), numPoets(0), novelists(nullptr), numNovelists(0), sciFiWriters(nullptr), numSciFiWriters(0) {}

PrintEdition::~PrintEdition() {
    delete[] poets;
    delete[] novelists;
    delete[] sciFiWriters;
}

void PrintEdition::addPoet(const std::string& name, const std::string& years, const std::string* majorWorks, int numMajorWorks) {
    Poet* newPoets = new Poet[numPoets + 1];
    for (int i = 0; i < numPoets; ++i) {
        newPoets[i] = poets[i];
    }
    newPoets[numPoets] = Poet(name, years, majorWorks, numMajorWorks);
    delete[] poets;
    poets = newPoets;
    ++numPoets;
}

void PrintEdition::addNovelist(const std::string& name, const std::string& years, const std::string* works, int numWorks, const std::string& biography) {
    Novelist* newNovelists = new Novelist[numNovelists + 1];
    for (int i = 0; i < numNovelists; ++i) {
        newNovelists[i] = novelists[i];
    }
    newNovelists[numNovelists] = Novelist(name, years, works, numWorks, biography);
    delete[] novelists;
    novelists = newNovelists;
    ++numNovelists;
}

void PrintEdition::addSciFiWriter(const std::string& name, const std::string* works, int numWorks, bool moviesAdaptation) {
    SciFiWriter* newSciFiWriters = new SciFiWriter[numSciFiWriters + 1];
    for (int i = 0; i < numSciFiWriters; ++i) {
        newSciFiWriters[i] = sciFiWriters[i];
    }
    newSciFiWriters[numSciFiWriters].name = name;
    newSciFiWriters[numSciFiWriters].numWorks = numWorks;
    newSciFiWriters[numSciFiWriters].moviesAdaptation = moviesAdaptation;
    newSciFiWriters[numSciFiWriters].works = new std::string[numWorks];
    for (int i = 0; i < numWorks; ++i) {
        newSciFiWriters[numSciFiWriters].works[i] = works[i];
    }
    delete[] sciFiWriters;
    sciFiWriters = newSciFiWriters;
    ++numSciFiWriters;
}

void PrintEdition::deletePoet(int index) {
    if (index >= 0 && index < numPoets) {
        for (int i = index; i < numPoets - 1; ++i) {
            poets[i] = poets[i + 1];
        }
        --numPoets;
    }
}

void PrintEdition::deleteNovelist(int index) {
    if (index >= 0 && index < numNovelists) {
        for (int i = index; i < numNovelists - 1; ++i) {
            novelists[i] = novelists[i + 1];
        }
        --numNovelists;
    }
}

void PrintEdition::deleteSciFiWriter(int index) {
    if (index >= 0 && index < numSciFiWriters) {
        for (int i = index; i < numSciFiWriters - 1; ++i) {
            sciFiWriters[i] = sciFiWriters[i + 1];
        }
        --numSciFiWriters;
    }
}

std::string PrintEdition::getPoetsInfo() const {
    std::string info = "Poets Info:\n";
    for (int i = 0; i < numPoets; ++i) {
        info += "Name: " + poets[i].name + "\n";
        info += "Years: " + poets[i].years + "\n";
        info += "Major Works:\n";
        for (int j = 0; j < poets[i].numMajorWorks; ++j) {
            info += "- " + poets[i].majorWorks[j] + "\n";
        }
        info += "\n";
    }
    return info;
}

std::string PrintEdition::getNovelistInfo() const {
    std::string info = "Novelists Info:\n";
    for (int i = 0; i < numNovelists; ++i) {
        info += "Name: " + novelists[i].name + "\n";
        info += "Years: " + novelists[i].years + "\n";
        info += "Biography: " + novelists[i].biography + "\n";
        info += "Works:\n";
        for (int j = 0; j < novelists[i].numWorks; ++j) {
            info += "- " + novelists[i].works[j] + "\n";
        }
        info += "\n";
    }
    return info;
}

std::string PrintEdition::getScifiwriterInfo() const {
    std::string info = "SciFi Writers Info:\n";
    for (int i = 0; i < numSciFiWriters; ++i) {
        info += "Name: " + sciFiWriters[i].name + "\n";
        info += "Number of Works: " + std::to_string(sciFiWriters[i].numWorks) + "\n";
        info += "Movies Adaptation: " + sciFiWriters[i].moviesAdaptation ? "Yes\n" : "No\n";
        info += "Works:\n";
        for (int j = 0; j < sciFiWriters[i].numWorks; ++j) {
            info += "- " + sciFiWriters[i].works[j] + "\n";
        }
        info += "\n";
    }
    return info;
}


std::string PrintEdition::getName() const {
    return name;
}
