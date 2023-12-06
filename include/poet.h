#ifndef POET_H
#define POET_H

#include "user.h"

class Poet : public User {
public:
    std::string* majorWorks;
    int numMajorWorks;
    Poet() : majorWorks(nullptr), numMajorWorks(0) {}  // Конструктор по умолчанию
    Poet(const std::string& name, const std::string& years, const std::string* majorWorks, int numMajorWorks);
    ~Poet();
    virtual std::string getPoetInfo() const;

};

#endif // POET_H
