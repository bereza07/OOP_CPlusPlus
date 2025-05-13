#pragma once
#include "User.h"

class Student : public User {
    std::string group;
public:
    Student(const std::string& name, int id, int accessLevel, const std::string& group);
    void displayInfo() const override;
    std::string getGroup() const {
        return group;
    }
};

