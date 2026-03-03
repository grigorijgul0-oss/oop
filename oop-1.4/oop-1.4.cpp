#include <iostream>
#include <string>
#include "Adress.h"

void showMenu() {
    std::cout << "\n=== ADDRESS MANAGEMENT MENU ===" << std::endl;
    std::cout << "1. Read Address from keyboard (Read method)" << std::endl;
    std::cout << "2. Display Address (Display method)" << std::endl;
    std::cout << "3. Show Address as string (toString method)" << std::endl;
    std::cout << "4. Change City" << std::endl;
    std::cout << "5. Change Street" << std::endl;
    std::cout << "6. Change Building" << std::endl;
    std::cout << "7. Change Zip Code" << std::endl;
    std::cout << "8. Show individual fields (Getters test)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select an option: ";
}

int main() {
    // --- 1. Демонстрація створення об'єктів і масивів (завдання) ---
    std::cout << "--- CREATION & ARRAY DEMONSTRATION ---" << std::endl;

    // Створення масиву об'єктів
    Address arr[2];
    arr[0].Init("Kyiv", "Khreshchatyk", "1", "01001");
    arr[1].Init("Lviv", "Rynok Sq", "10", "79000");
    std::cout << "Array of addresses created successfully." << std::endl;

    // Створення та ліквідація динамічного об'єкта
    Address* dynAddress = new Address();
    dynAddress->Init("Odessa", "Deribasivska", "5", "65000");
    std::cout << "Dynamic object created: " << dynAddress->toString() << std::endl;
    delete dynAddress; // Ліквідація об'єкта
    std::cout << "Dynamic object deleted." << std::endl;

    std::cout << "\n----------------------------------------\n";

    // --- 2. Інтерактивне меню для перевірки методів ---
    Address myAddress;
    myAddress.Init("TestCity", "TestStreet", "TestBld", "12345");

    int choice;
    std::string tempInput;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            myAddress.Read();
            break;
        case 2:
            myAddress.Display();
            break;
        case 3:
            std::cout << "String: " << myAddress.toString() << std::endl;
            break;
        case 4:
            std::cout << "Enter new City: ";
            std::getline(std::cin >> std::ws, tempInput);
            myAddress.setCity(tempInput);
            break;
        case 5:
            std::cout << "Enter new Street: ";
            std::getline(std::cin >> std::ws, tempInput);
            myAddress.setStreet(tempInput);
            break;
        case 6:
            std::cout << "Enter new Building: ";
            std::getline(std::cin >> std::ws, tempInput);
            myAddress.setBuilding(tempInput);
            break;
        case 7:
            std::cout << "Enter new Zip Code: ";
            std::getline(std::cin >> std::ws, tempInput);
            myAddress.setZipCode(tempInput);
            break;
        case 8:
            std::cout << "City: " << myAddress.getCity() << std::endl;
            std::cout << "Street: " << myAddress.getStreet() << std::endl;
            std::cout << "Bldg: " << myAddress.getBuilding() << std::endl;
            std::cout << "Zip: " << myAddress.getZipCode() << std::endl;
            break;
        case 0:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}