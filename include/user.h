#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string name;
    std::string years;
    virtual void displayInfo() const;
    virtual ~User() = default;
};

#endif // USER_H
