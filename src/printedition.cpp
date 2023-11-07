#include "printedition.h"

PrintEdition::PrintEdition(const std::string& name) : name(name) {
    poets = nullptr;
    numPoets = 0;
    novelists = nullptr;
    numNovelists = 0;
    sciFiWriters = nullptr;
    numSciFiWriters = 0;
}

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
    if (poets != nullptr) {
        delete[] poets;
    }
    poets = newPoets;
    poets[numPoets].name = name;
    poets[numPoets].years = years;
    poets[numPoets].numMajorWorks = numMajorWorks;
    poets[numPoets].majorWorks = new std::string[numMajorWorks];
    for (int i = 0; i < numMajorWorks; ++i) {
        poets[numPoets].majorWorks[i] = majorWorks[i];
    }
    numPoets++;
}

void PrintEdition::addNovelist(const std::string& name, const std::string& years, const std::string* works, int numWorks, const std::string& biography) {
    Novelist* newNovelists = new Novelist[numNovelists + 1];
    for (int i = 0; i < numNovelists; ++i) {
        newNovelists[i] = novelists[i];
    }
    if (novelists != nullptr) {
        delete[] novelists;
    }
    novelists = newNovelists;
    novelists[numNovelists].name = name;
    novelists[numNovelists].years = years;
    novelists[numNovelists].numWorks = numWorks;
    novelists[numNovelists].works = new std::string[numWorks];
    for (int i = 0; i < numWorks; ++i) {
        novelists[numNovelists].works[i] = works[i];
    }
    novelists[numNovelists].biography = biography;
    numNovelists++;
}

void PrintEdition::addSciFiWriter(const std::string& name, const std::string* works, int numWorks, bool moviesAdaptation) {
    SciFiWriter* newSciFiWriters = new SciFiWriter[numSciFiWriters + 1];
    for (int i = 0; i < numSciFiWriters; ++i) {
        newSciFiWriters[i] = sciFiWriters[i];
    }
    if (sciFiWriters != nullptr) {
        delete[] sciFiWriters;
    }
    sciFiWriters = newSciFiWriters;
    sciFiWriters[numSciFiWriters].name = name;
    sciFiWriters[numSciFiWriters].numWorks = numWorks;
    sciFiWriters[numSciFiWriters].works = new std::string[numWorks];
    for (int i = 0; i < numWorks; ++i) {
        sciFiWriters[numSciFiWriters].works[i] = works[i];
    }
    sciFiWriters[numSciFiWriters].moviesAdaptation = moviesAdaptation;
    numSciFiWriters++;
}

// В классе PrintEdition добавьте методы удаления поэтов, романистов и фантастов
void PrintEdition::deletePoet(int index) {
    if (index >= 0 && index < numPoets) {
        delete[] poets[index].majorWorks;
        for (int i = index; i < numPoets - 1; ++i) {
            poets[i] = poets[i + 1];
        }
        numPoets--;
    }
}

void PrintEdition::deleteNovelist(int index) {
    if (index >= 0 && index < numNovelists) {
        delete[] novelists[index].works;
        for (int i = index; i < numNovelists - 1; ++i) {
            novelists[i] = novelists[i + 1];
        }
        numNovelists--;
    }
}

void PrintEdition::deleteSciFiWriter(int index) {
    if (index >= 0 && index < numSciFiWriters) {
        delete[] sciFiWriters[index].works;
        for (int i = index; i < numSciFiWriters - 1; ++i) {
            sciFiWriters[i] = sciFiWriters[i + 1];
        }
        numSciFiWriters--;
    }
}

std::string PrintEdition::getName() const {
    return name;
}

