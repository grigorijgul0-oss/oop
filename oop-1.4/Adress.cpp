#include "Adress.h"
#include <iostream>
#include <sstream>

// Конструктор
Address::Address() {
    city = "Unknown";
    street = "Unknown";
    building = "Unknown";
    zipCode = "00000";
}

// Деструктор (виводимо повідомлення, щоб бачити момент ліквідації об'єкта)
Address::~Address() {
    // Деструктор викликається автоматично при видаленні об'єкта
}

// === Геттери ===
std::string Address::getCity() const { return city; }
std::string Address::getStreet() const { return street; }
std::string Address::getBuilding() const { return building; }
std::string Address::getZipCode() const { return zipCode; }

// === Сеттери з контролем коректності ===
void Address::setCity(const std::string& newCity) {
    if (!newCity.empty()) { city = newCity; }
    else { city = "Unknown"; std::cerr << "Error: City cannot be empty.\n"; }
}

void Address::setStreet(const std::string& newStreet) {
    if (!newStreet.empty()) { street = newStreet; }
    else { street = "Unknown"; std::cerr << "Error: Street cannot be empty.\n"; }
}

void Address::setBuilding(const std::string& newBuilding) {
    if (!newBuilding.empty()) { building = newBuilding; }
    else { building = "Unknown"; std::cerr << "Error: Building cannot be empty.\n"; }
}

void Address::setZipCode(const std::string& newZipCode) {
    // Проста перевірка: індекс не може бути порожнім і має мати хоча б 3 символи
    if (!newZipCode.empty() && newZipCode.length() >= 3) { zipCode = newZipCode; }
    else { zipCode = "00000"; std::cerr << "Error: Invalid Zip Code.\n"; }
}

// === Обов'язкові методи ===
void Address::Init(const std::string& c, const std::string& s, const std::string& b, const std::string& z) {
    // Використовуємо сеттери, щоб неможливо було обійти перевірку!
    setCity(c);
    setStreet(s);
    setBuilding(b);
    setZipCode(z);
}

void Address::Read() {
    std::string c, s, b, z;

    // std::ws очищає потік від зайвих пробілів (Enter) перед вводом рядка
    std::cout << "Enter City: ";
    std::getline(std::cin >> std::ws, c);

    std::cout << "Enter Street: ";
    std::getline(std::cin >> std::ws, s);

    std::cout << "Enter Building: ";
    std::getline(std::cin >> std::ws, b);

    std::cout << "Enter Zip Code: ";
    std::getline(std::cin >> std::ws, z);

    Init(c, s, b, z);
}

void Address::Display() const {
    std::cout << "Address: " << zipCode << ", " << city
        << ", " << street << " st., bld. " << building << std::endl;
}

std::string Address::toString() const {
    std::ostringstream oss;
    oss << "[Zip: " << zipCode << " | City: " << city
        << " | Street: " << street << " | Bldg: " << building << "]";
    return oss.str();
}