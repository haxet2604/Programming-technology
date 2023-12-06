#include "Keeper.h"

Keeper::Keeper() : numPrintEditions(0) {
    // конструктор
}

void Keeper::addPrintEdition(const std::string& name) {
    if (numPrintEditions < MAX_PRINT_EDITIONS) {
        database[numPrintEditions++] = new PrintEdition(name);
    } else {
        std::cout << "Database is full, cannot add more PrintEditions." << std::endl;
    }
}

void Keeper::deletePrintEdition(int index) {
    if (index >= 0 && index < numPrintEditions) {
        delete database[index];
        for (int i = index; i < numPrintEditions - 1; ++i) {
            database[i] = database[i + 1];
        }
        --numPrintEditions;
    } else {
        std::cout << "Invalid index to delete PrintEdition." << std::endl;
    }
}

PrintEdition* Keeper::getPrintEdition(int index) {
    if (index >= 0 && index < numPrintEditions) {
        return database[index];
    }
    return nullptr;
}

int Keeper::getDatabaseSize() const {
    return numPrintEditions;
}

void Keeper::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numPrintEditions; ++i) {
            file << database[i]->getName() << "\n";
        }
        std::cout << "Database saved to file: " << filename << std::endl;
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        while (std::getline(file, name)) {
            addPrintEdition(name);
        }
        std::cout << "Database loaded from file: " << filename << std::endl;
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

void Keeper::displayDatabase() const {
    for (int i = 0; i < numPrintEditions; ++i) {
        std::cout << i + 1 << ". " << database[i]->getName() << std::endl;
    }
}

void Keeper::saveDatabase(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numPrintEditions; ++i) {
            file << "Print Edition: " << database[i]->getName() << "\n";
            
            // Saving poets' information
            file << "Poets:\n";
            file << database[i]->getPoetsInfo(); // Assuming getPoetsInfo returns poets' information
            
            // Saving novelists' information
            file << "Novelists:\n";
            file << database[i]->getNovelistInfo(); // Assuming getNovelistsInfo returns novelists' information
            
            // Saving sci-fi writers' information
            file << "Sci-Fi Writers:\n";
            file << database[i]->getScifiwriterInfo(); // Assuming getSciFiWritersInfo returns sci-fi writers' information
            
            file << "\n";
        }
        std::cout << "Database saved to file: " << filename << std::endl;
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}


Keeper::~Keeper() {
    for (int i = 0; i < numPrintEditions; ++i) {
        delete database[i];
    }
}
