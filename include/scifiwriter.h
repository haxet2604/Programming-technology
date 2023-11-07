#ifndef SCIFIWRITER_H
#define SCIFIWRITER_H

#include "user.h"

class SciFiWriter : public User {
public:
    std::string* works;
    int numWorks;
    bool moviesAdaptation;

    SciFiWriter() : works(nullptr), numWorks(0), moviesAdaptation(false) {}

    SciFiWriter(const std::string& name, const std::string& years, const std::string* works, int numWorks, bool moviesAdaptation);
    ~SciFiWriter();
    void displayInfo() const override;
};

#endif // SCIFIWRITER_H
