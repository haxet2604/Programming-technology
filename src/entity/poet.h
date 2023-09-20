#include <iostream>
#include "user.h"

#ifndef POET_H
#define POET_H

using namespace std;

class Poet : public User
{
public:
    Poet(string first_name, string surname, string last_name) : User(first_name, surname, last_name) {};
    ~Poet();

    string getFirstName() const override;
    string getSurname() const override {
        return this->surname;
    };
    string getLastName() const override {
        return this->last_name;
    };
};

#endif