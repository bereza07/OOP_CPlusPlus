#pragma once
#include "User.h"


class Teacher : public User {
    std::string department;
public:
    Teacher(const std::string& name, int id, int accessLevel, const std::string& dept);
    void displayInfo() const override;
    std::string getSubject() const {
        return department;
    }
};

