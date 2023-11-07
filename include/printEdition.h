#ifndef PRINTEDITION_H
#define PRINTEDITION_H

#include <string>
#include "poet.h"
#include "novelist.h"
#include "scifiwriter.h"

class PrintEdition {
public:
    PrintEdition() {}
    PrintEdition(const std::string& name);
    ~PrintEdition();
    void addPoet(const std::string& name, const std::string& years, const std::string* majorWorks, int numMajorWorks);
    void addNovelist(const std::string& name, const std::string& years, const std::string* works, int numWorks, const std::string& biography);
    void addSciFiWriter(const std::string& name, const std::string* works, int numWorks, bool moviesAdaptation);

    void deletePoet(int index);
    void deleteNovelist(int index);
    void deleteSciFiWriter(int index);

    std::string getName() const; 
private:
    Poet* poets;
    int numPoets;
    Novelist* novelists;
    int numNovelists;
    SciFiWriter* sciFiWriters;
    int numSciFiWriters;
    
    std::string name;
};

#endif // PRINTEDITION_H
