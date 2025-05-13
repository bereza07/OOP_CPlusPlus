#pragma once
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

template<typename U, typename R>
class AccessControlSystem {
    std::vector<std::shared_ptr<U>> users;
    std::vector<R> resources;

public:
    void addUser(std::shared_ptr<U> user) { users.push_back(user); }
    void addResource(const R& res) { resources.push_back(res); }

    void listUsers() const {
        for (const auto& user : users) user->displayInfo();
    }

    void listResources() const {
        for (const auto& res : resources) res.display();
    }

    void checkAccess(int userId, const std::string& resName) const {
        auto userIt = std::find_if(users.begin(), users.end(),
            [userId](const std::shared_ptr<U>& u) { return u->getId() == userId; });

        auto resIt = std::find_if(resources.begin(), resources.end(),
            [resName](const R& r) { return r.getName() == resName; });

        if (userIt == users.end()) {
            std::cerr << "Пользователь не найден.\n";
            return;
        }
        if (resIt == resources.end()) {
            std::cerr << "Ресурс не найден.\n";
            return;
        }

        if (resIt->checkAccess(**userIt)) std::cout << "Доступ разрешен.\n";
        else std::cout << "Доступ запрещен.\n";
    }

    void saveUsersToFile(const std::string& filename) const {
        std::ofstream out(filename);

        if (!out) {
            throw std::ios_base::failure("Не удалось открыть файл для записи.");
        }

        // Записываем данные для каждого пользователя
        for (const auto& user : users) {
            // Сохраняем ID, имя, уровень доступа и дополнительные данные, специфичные для каждого типа пользователя
            out << user->getId() << " " << user->getName() << " " << user->getAccessLevel();

            if (auto student = std::dynamic_pointer_cast<Student>(user)) {
                out << " " << student->getGroup(); // для студентов сохраняем группу
            }
            else if (auto teacher = std::dynamic_pointer_cast<Teacher>(user)) {
                out << " " << teacher->getSubject(); // для преподавателей сохраняем предмет
            }
            else if (auto admin = std::dynamic_pointer_cast<Administrator>(user)) {
                out << " " << admin->getRole(); // для администраторов сохраняем департамент
            }

            out << "\n";
        }

        out.close();
    }


    void loadUsersFromFile(const std::string& filename, const std::function<std::shared_ptr<User>(const std::string&, int, int, std::string additionalData)>& userFactory) {
        std::ifstream file(filename);
        if (!file) {
            throw std::ios_base::failure("Не удалось открыть файл для чтения.");
        }

        std::string name;
        int id, level;
        std::string additionalData;

        while (file >> id >> name >> level >> additionalData) {
            std::cout << "Чтение данных: ID=" << id << ", Name=" << name << ", Level=" << level << ", AdditionalData=" << additionalData << std::endl;
            try {
                // Создаём пользователя через фабричный метод
                users.push_back(userFactory(name, id, level, additionalData));
            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка при создании пользователя: " << e.what() << std::endl;
            }
        }

        file.close();
    }

    void clearUsers() {
        users.clear();
    }

    std::shared_ptr<U> findUserByName(const std::string& searchName) const {
        for (const auto& user : users) {
            if (user->getName() == searchName) return user;
        }
        return nullptr;
    }

    void sortUsersByAccessLevel() {
        std::sort(users.begin(), users.end(),
            [](const std::shared_ptr<U>& a, const std::shared_ptr<U>& b) {
                return a->getAccessLevel() < b->getAccessLevel();
            });
    }
    std::shared_ptr<U> findUserById(int id) const {
        auto it = std::find_if(users.begin(), users.end(),
            [id](const std::shared_ptr<U>& user) {
                return user->getId() == id;
            });
        return (it != users.end()) ? *it : nullptr;
    }

    const std::vector<std::shared_ptr<U>>& getUsers() const {
        return users;
    }

};