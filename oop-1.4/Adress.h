#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    std::string building;
    std::string zipCode;

public:
    // Конструктор та деструктор (демонстрація створення і ліквідації)
    Address();
    ~Address();

    // Методи доступу (геттери) - константні
    std::string getCity() const;
    std::string getStreet() const;
    std::string getBuilding() const;
    std::string getZipCode() const;

    // Методи запису (сеттери) з перевіркою на коректність
    void setCity(const std::string& newCity);
    void setStreet(const std::string& newStreet);
    void setBuilding(const std::string& newBuilding);
    void setZipCode(const std::string& newZipCode);

    // Обов'язкові методи за завданням
    void Init(const std::string& c, const std::string& s, const std::string& b, const std::string& z);
    void Read();
    void Display() const;
    std::string toString() const;
};

#endif // ADDRESS_H