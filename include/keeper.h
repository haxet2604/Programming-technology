#ifndef KEEPER_H
#define KEEPER_H

#include "printedition.h"

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addPrintEdition(const PrintEdition& printEdition);
    void deletePrintEdition(int index);
    void saveDatabase(const std::string& filename) const;
    void loadDatabase(const std::string& filename);
    void displayDatabase() const;

private:
    PrintEdition* database;
    int numEditions;
    int capacity;

    void resizeDatabase();
};

#endif // KEEPER_H
