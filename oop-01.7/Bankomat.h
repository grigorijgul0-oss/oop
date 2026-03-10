#pragma once
#include "Money.h"
#include <string>

class Bankomat {
private:
    std::string id;
    Money balance;
    double minWithdrawal;
    double maxWithdrawal;

public:
    Bankomat();

    // Ініціалізація
    void Init(std::string atm_id, const Money& initial_balance, double min_w, double max_w);

    // Введення/Виведення
    void Read();
    void Display() const;
    std::string toString() const;

    // Методи доступу
    std::string getId() const { return id; }
    Money getBalance() const { return balance; }
    double getMin() const { return minWithdrawal; }
    double getMax() const { return maxWithdrawal; }

    void setId(const std::string& new_id);
    void setBalance(const Money& new_balance);
    void setLimits(double min_w, double max_w); // валідація лімітів

    // Основні бізнес-методи
    void LoadBills(const Money& m);
    void Withdraw(double amount);
};