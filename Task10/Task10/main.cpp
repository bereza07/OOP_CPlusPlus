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
        // Создаем систему контроля доступа
        AccessControlSystem<User, Resource> system;

        // Добавляем пользователей
        system.addUser(std::make_shared<Student>("Влад", 1, 2, "Т.РИ22"));
        system.addUser(std::make_shared<Teacher>("Петров", 2, 4, "Физика"));
        system.addUser(std::make_shared<Administrator>("Сидоров", 3, 5, "Админ"));

        // Добавляем ресурсы
        system.addResource(Resource("Лаборатория", 3));
        system.addResource(Resource("Библиотека", 1));

        // Выводим пользователей
        std::cout << "\nПользователи:\n";
        system.listUsers();

        // Выводим ресурсы
        std::cout << "\nРесурсы:\n";
        system.listResources();

        // Проверка доступа
        std::cout << "\nПроверка доступа:\n";
        system.checkAccess(1, "Лаборатория");

        // Поиск пользователя по ID
        std::cout << "\nПоиск по ID:\n";
        auto foundById = system.findUserById(2);
        if (foundById) {
            foundById->displayInfo();
        }
        else {
            std::cout << "Пользователь с ID 2 не найден.\n";
        }

        // Поиск пользователя по имени
        std::cout << "\nПоиск по имени:\n";
        auto foundByName = system.findUserByName("Иван");
        if (foundByName) {
            foundByName->displayInfo();
        }
        else {
            std::cout << "Пользователь с именем 'Иван' не найден.\n";
        }

        // Сортировка пользователей по уровню доступа
        std::cout << "\nСортировка по уровню доступа:\n";
        system.sortUsersByAccessLevel();
        system.listUsers();

        // Сохраняем пользователей в файл
        system.saveUsersToFile("Users.txt");

        // Загружаем пользователей из файла
        try {
            // Очистить старые данные перед загрузкой новых
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
                    throw std::invalid_argument("Неизвестный уровень доступа.");
                }
                });

            std::cout << "Пользователи успешно загружены.\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка при загрузке пользователей: " << e.what() << '\n';
        }

        // Выводим всех пользователей после загрузки
        std::cout << "\nПользователи после загрузки:\n";
        for (const auto& user : system.getUsers()) {
            user->displayInfo();
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
