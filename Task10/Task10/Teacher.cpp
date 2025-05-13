#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const std::string& name, int id, int accessLevel, const std::string& dept)
    : User(name, id, accessLevel), department(dept) {}

void Teacher::displayInfo() const {
    std::cout << "Teacher: " << name << ", ID: " << id << ", Department: " << department
        << ", Access Level: " << accessLevel << std::endl;
}