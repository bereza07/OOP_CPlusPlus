#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& name, int id, int accessLevel, const std::string& role)
    : User(name, id, accessLevel), role(role) {}

void Administrator::displayInfo() const {
    std::cout << "Administrator: " << name << ", ID: " << id << ", Role: " << role
        << ", Access Level: " << accessLevel << std::endl;
}