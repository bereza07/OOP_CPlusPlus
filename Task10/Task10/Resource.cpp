#include "Resource.h"
#include <iostream>

Resource::Resource(const std::string& name, int level)
    : resourceName(name), requiredAccessLevel(level) {}

std::string Resource::getName() const { return resourceName; }
int Resource::getRequiredAccessLevel() const { return requiredAccessLevel; }

bool Resource::checkAccess(const User& user) const {
    return user.getAccessLevel() >= requiredAccessLevel;
}

void Resource::display() const {
    std::cout << "Resource: " << resourceName << ", Required Access: " << requiredAccessLevel << std::endl;
}