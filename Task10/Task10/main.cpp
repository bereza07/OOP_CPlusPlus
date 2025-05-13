#include <iostream>
#include <memory>
#include <vector>
#include "AccessControlSystem.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Resource.h"

int main() {
    setlocale(LC_ALL, "Rus");

    try {
        // ������� ������� �������� �������
        AccessControlSystem<User, Resource> system;

        // ��������� �������������
        system.addUser(std::make_shared<Student>("����", 1, 2, "�.��22"));
        system.addUser(std::make_shared<Teacher>("������", 2, 4, "������"));
        system.addUser(std::make_shared<Administrator>("�������", 3, 5, "�����"));

        // ��������� �������
        system.addResource(Resource("�����������", 3));
        system.addResource(Resource("����������", 1));

        // ������� �������������
        std::cout << "\n������������:\n";
        system.listUsers();

        // ������� �������
        std::cout << "\n�������:\n";
        system.listResources();

        // �������� �������
        std::cout << "\n�������� �������:\n";
        system.checkAccess(1, "�����������");

        // ����� ������������ �� ID
        std::cout << "\n����� �� ID:\n";
        auto foundById = system.findUserById(2);
        if (foundById) {
            foundById->displayInfo();
        }
        else {
            std::cout << "������������ � ID 2 �� ������.\n";
        }

        // ����� ������������ �� �����
        std::cout << "\n����� �� �����:\n";
        auto foundByName = system.findUserByName("����");
        if (foundByName) {
            foundByName->displayInfo();
        }
        else {
            std::cout << "������������ � ������ '����' �� ������.\n";
        }

        // ���������� ������������� �� ������ �������
        std::cout << "\n���������� �� ������ �������:\n";
        system.sortUsersByAccessLevel();
        system.listUsers();

        // ��������� ������������� � ����
        system.saveUsersToFile("Users.txt");

        // ��������� ������������� �� �����
        try {
            // �������� ������ ������ ����� ��������� �����
            system.clearUsers();

            system.loadUsersFromFile("Users.txt", [](const std::string& name, int id, int level, std::string additionalData) {
                if (level == 2) {
                    return std::static_pointer_cast<User>(std::make_shared<Student>(name, id, level, additionalData));
                }
                else if (level == 4) {
                    return std::static_pointer_cast<User>(std::make_shared<Teacher>(name, id, level, additionalData));
                }
                else if (level == 5) {
                    return std::static_pointer_cast<User>(std::make_shared<Administrator>(name, id, level, additionalData));
                }
                else {
                    throw std::invalid_argument("����������� ������� �������.");
                }
                });

            std::cout << "������������ ������� ���������.\n";
        }
        catch (const std::exception& e) {
            std::cerr << "������ ��� �������� �������������: " << e.what() << '\n';
        }

        // ������� ���� ������������� ����� ��������
        std::cout << "\n������������ ����� ��������:\n";
        for (const auto& user : system.getUsers()) {
            user->displayInfo();
        }

    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}
