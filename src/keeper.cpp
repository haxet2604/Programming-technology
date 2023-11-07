#include "keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper()
{
    numEditions = 0;
    capacity = 10;
    database = new PrintEdition[capacity];
}

Keeper::~Keeper()
{
    delete[] database;
}

void Keeper::resizeDatabase()
{
    capacity *= 2;
    PrintEdition *newDatabase = new PrintEdition[capacity];
    for (int i = 0; i < numEditions; ++i)
    {
        newDatabase[i] = database[i];
    }
    delete[] database;
    database = newDatabase;
}

void Keeper::addPrintEdition(const PrintEdition &printEdition)
{
    if (numEditions >= capacity)
    {
        resizeDatabase();
    }
    database[numEditions] = printEdition;
    numEditions++;
}

void Keeper::deletePrintEdition(int index)
{
    if (index >= 0 && index < numEditions)
    {
        for (int i = index; i < numEditions - 1; ++i)
        {
            database[i] = database[i + 1];
        }
        numEditions--;
    }
}

void Keeper::saveDatabase(const std::string& filename) const {
    // std::ofstream outFile(filename);
    // if (outFile.is_open()) {
    //     for (int i = 0; i < numEditions; ++i) {
    //         outFile << database[i].getName() << "\n";
            
    //         Poet* poet = dynamic_cast<Poet*>(&database[i]);
    //         Novelist* novelist = dynamic_cast<Novelist*>(&database[i]);
    //         SciFiWriter* sciFiWriter = dynamic_cast<SciFiWriter*>(&database[i]);

    //         if (poet) {
    //             // Это поэт
    //             outFile << "Poet\n";
    //         } else if (novelist) {
    //             outFile << "Novelist\n";
    //         } else if (sciFiWriter) {
    //             outFile << "SciFiWriter\n";
    //         }

    //     }
    //     outFile.close();
    // } else {
    //     std::cerr << "Невозможно сохранить файл: " << filename << std::endl;
    // }
}


void Keeper::loadDatabase(const std::string &filename)
{
    // std::ifstream inFile(filename);
    // if (inFile.is_open())
    // {
    //     delete[] database;
    //     numEditions = 0;
    //     capacity = 10;
    //     database = new PrintEdition[capacity];

    //     std::string line;
    //     while (std::getline(inFile, line))
    //     {
    //         if (line == "Poet")
    //         {
    //             // Это поэт, считываем данные и создаем объект Poet
    //             std::string name, biography;
    //             // Считываем данные из файла и создаем объект Poet
    //             Poet poet(name, biography, /* другие параметры по желанию */);
    //             addPrintEdition(poet);
    //         }
    //         else if (line == "Novelist")
    //         {
    //             // Это романист, считываем данные и создаем объект Novelist
    //             std::string name, biography;
    //             // Считываем данные из файла и создаем объект Novelist
    //             Novelist novelist(name, biography, /* другие параметры по желанию */);
    //             addPrintEdition(novelist);
    //         }
    //         else if (line == "SciFiWriter")
    //         {
    //             // Это фантаст, считываем данные и создаем объект SciFiWriter
    //             std::string name, biography;
    //             // Считываем данные из файла и создаем объект SciFiWriter
    //             SciFiWriter sciFiWriter(name, biography, /* другие параметры по желанию */);
    //             addPrintEdition(sciFiWriter);
    //         }
    //     }
    //     inFile.close();
    // }
    // else
    // {
    //     std::cerr << "Невозможно загрузить файл: " << filename << std::endl;
    // }
}

void Keeper::displayDatabase() const
{
    for (int i = 0; i < numEditions; ++i)
    {
        std::cout << "Печатное издание #" << i + 1 << std::endl;
        std::cout << "Имя: " << database[i].getName() << std::endl;
        // Выводите остальные данные печатного издания в зависимости от его типа (поэт, романист или фантаст)
        std::cout << std::endl;
    }
}
