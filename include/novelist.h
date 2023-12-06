#ifndef NOVELIST_H
#define NOVELIST_H

#include "user.h"

class Novelist : public User {
public:
    std::string* works;
    int numWorks;
    std::string biography;

    Novelist() : works(nullptr), numWorks(0) {}  // Конструктор по умолчанию
    Novelist(const std::string& name, const std::string& years, const std::string* works, int numWorks, const std::string& biography);
    ~Novelist();
    virtual std::string getNovelistsInfo() const;
};

#endif // NOVELIST_H
