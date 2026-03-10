#include "Bankomat.h"
#include <iostream>
#include <stdexcept>

Bankomat::Bankomat() {
    minWithdrawal = 0;
    maxWithdrawal = 0;
}

void Bankomat::Init(std::string atm_id, const Money& initial_balance, double min_w, double max_w) {
    setId(atm_id);
    setBalance(initial_balance);
    setLimits(min_w, max_w);
}

void Bankomat::setId(const std::string& new_id) {
    if (new_id.empty()) throw std::invalid_argument("ID cannot be empty");
    id = new_id;
}

void Bankomat::setBalance(const Money& new_balance) {
    balance = new_balance;
}

void Bankomat::setLimits(double min_w, double max_w) {
    if (min_w < 0 || max_w < min_w) throw std::invalid_argument("Invalid limits");
    minWithdrawal = min_w;
    maxWithdrawal = max_w;
}

void Bankomat::Read() {
    std::string new_id;
    double min_w, max_w;

    std::cout << "Enter ATM ID: ";
    std::cin >> new_id;
    setId(new_id);

    std::cout << "\nEnter initial ATM balance:\n";
    balance.Read();

    std::cout << "\nEnter min and max withdrawal limits (in UAH, space separated): ";
    std::cin >> min_w >> max_w;
    setLimits(min_w, max_w);
}

void Bankomat::Display() const {
    std::cout << "--- Bankomat [" << id << "] ---\n"
        << "Current Balance: " << toString() << "\n"
        << "Limits: " << minWithdrawal << " to " << maxWithdrawal << " UAH\n";
}

std::string Bankomat::toString() const {
    // Згідно з завданням, метод toString має повертати рядок суми грошей, що залишилась
    return balance.toString();
}

void Bankomat::LoadBills(const Money& m) {
    balance = balance.Add(m);
    std::cout << "Loaded bills. New balance: " << balance.toString() << "\n";
}

void Bankomat::Withdraw(double amount) {
    if (amount < minWithdrawal || amount > maxWithdrawal) {
        std::cout << "Error: Requested amount " << amount
            << " is out of limits (" << minWithdrawal << " - " << maxWithdrawal << ")\n";
        return;
    }

    // Створюємо тимчасовий об'єкт Money, що відповідає сумі для зняття
    Money reqMoney;
    reqMoney.Init(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (int)(amount * 100)); // конвертуємо у копійки
    // Використовуємо метод MultiplyFraction для правильної трансформації 
    reqMoney = reqMoney.MultiplyFraction(1.0); // Нормалізація

    try {
        balance = balance.Subtract(reqMoney);
        std::cout << "Successfully withdrew " << amount << " UAH.\n"
            << "Remaining balance: " << toString() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: Not enough funds in the ATM for this operation.\n";
    }
}