#include <iostream>
#include <fstream>
#include "poet.h"
#include "user.h"

using namespace std;

class Database
{
private:
    string fileName;
    ofstream file;

public:
    Database(string fileName);

    Poet getUser(Poet id);
    Poet setUser(Poet user);

    ~Database();
};

Database::Database(string fileName) : fileName(fileName), file(fileName, ios::app)
{
    
}

Database::~Database()
{
    this->file.close();
}

Poet Database::setUser(Poet poet)
{
    file << poet.getFirstName() << "," << poet.getSurname() << "," << poet.getLastName() << endl;
    return poet;
}