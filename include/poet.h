#include <iostream>
#include "user.h"
#pragma once

#ifndef POET_H
#define POET_H

using namespace std;

class Poet : public User
{
public:
    Poet(string first_name, string surname, string last_name);
    ~Poet();

    string getFirstName() const;
    string getSurname() const;
    string getLastName() const;
};

#endif