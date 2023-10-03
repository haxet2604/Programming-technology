#include <iostream>
#pragma once

#ifndef USER_H
#define USER_H

using namespace std;

class User
{
protected:
    string first_name;
    string surname;
    string last_name;
    int id;

public:
    User(string first_name, string surname, string last_name);
    ~User();

    virtual string getFirstName() const = 0;
    virtual string getSurname() const = 0;
    virtual string getLastName() const = 0;
};

#endif