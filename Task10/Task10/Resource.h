#pragma once
#include <string>
#include "User.h"

class Resource {
    std::string resourceName;
    int requiredAccessLevel;

public:
    Resource(const std::string& name, int level);
    std::string getName() const;
    int getRequiredAccessLevel() const;
    bool checkAccess(const User& user) const;
    void display() const;
};

