#ifndef KEEPER_H
#define KEEPER_H

#include <iostream>
#include <fstream>
#include "PrintEdition.h"

class Keeper {
private:
    static const int MAX_PRINT_EDITIONS = 100;
    PrintEdition* database[MAX_PRINT_EDITIONS];
    int numPrintEditions;

public:
    Keeper();

    void addPrintEdition(const std::string& name);

    void deletePrintEdition(int index);

    PrintEdition* getPrintEdition(int index);

    int getDatabaseSize() const;

    void saveToFile(const std::string& filename);

    void loadFromFile(const std::string& filename);

    void displayDatabase() const;

    void saveDatabase(const std::string& filename) const;

    ~Keeper();
};

#endif // KEEPER_H
