#include "user.h"

User::User(string firstName, string surname, string lastName) {
    this->first_name = firstName;
    this->surname = surname;
    this->last_name = lastName;
};

User::~User()
{
}
