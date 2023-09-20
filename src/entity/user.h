#include <iostream>

#ifndef USER_H
#define USER_H

using namespace std;

class User
{
private:
    string first_name;
    string surname;
    string last_name;

public:
    User(string first_name, string surname, string last_name);
    ~User();
};

#endif