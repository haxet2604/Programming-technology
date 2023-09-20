#include "poet.h"
#include "user.h"

Poet::Poet(string firstName, string surname, string lastName) : User(firstName, surname, lastName) {};

string Poet::getFirstName() const {
    return this->first_name;
}

string Poet::getLastName() const {
    return this->last_name;
}

string Poet::getSurname() const {
    return this->surname;
}