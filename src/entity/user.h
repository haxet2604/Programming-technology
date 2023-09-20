#include <iostream>

#ifndef USER_H
#define USER_H

using namespace std;

class User
{
protected:
    string first_name;
    string surname;
    string last_name;

public:
    User(string first_name, string surname, string last_name);
    ~User();

    virtual string getFirstName() const = 0;
    virtual string getSurname() const = 0;
    virtual string getLastName() const = 0;
};

#endif