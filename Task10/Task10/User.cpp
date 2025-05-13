#include "User.h"
#include <stdexcept>

User::User(const std::string& name, int id, int accessLevel) {
    if (name.empty()) throw std::invalid_argument("��� �� ����� ���� ������.");
    if (id < 0 || accessLevel < 0) throw std::invalid_argument("ID � ������� ������� �� ����� ���� ��������������.");
    this->name = name;
    this->id = id;
    this->accessLevel = accessLevel;
}

User::~User() {}

std::string User::getName() const { return name; }
int User::getId() const { return id; }
int User::getAccessLevel() const { return accessLevel; }

void User::setName(const std::string& newName) {
    if (newName.empty()) throw std::invalid_argument("��� �� ����� ���� ������.");
    name = newName;
}

void User::setAccessLevel(int level) {
    if (level < 0) throw std::invalid_argument("������� ������� �� ����� ���� �������������.");
    accessLevel = level;
}