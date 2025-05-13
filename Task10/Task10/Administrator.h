#pragma once
#include "User.h"
class Administrator : public User {
    std::string role;
public:
    Administrator(const std::string& name, int id, int accessLevel, const std::string& role);
    void displayInfo() const override;
    std::string getRole() const {
        return role;
    }
};


