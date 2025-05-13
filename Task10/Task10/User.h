#pragma once
#include <string>

class User {
protected:
    std::string name;
    int id;
    int accessLevel;

public:
    User(const std::string& name, int id, int accessLevel);
    virtual ~User();

    std::string getName() const;
    int getId() const;
    int getAccessLevel() const;

    void setName(const std::string& newName);
    void setAccessLevel(int level);

    virtual void displayInfo() const = 0;
};

