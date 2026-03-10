#include "Money.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

Money::Money() { Init(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); }

void Money::Init(int n500, int n200, int n100, int n50, int n20, int n10, int n5, int n2, int n1,
    int m50, int m25, int m10, int m5, int m2, int m1) {
    set500(n500); set200(n200); set100(n100); set50(n50); set20(n20); set10(n10); set5(n5); set2(n2); set1(n1);
    setC50(m50); setC25(m25); setC10(m10); setC5(m5); setC2(m2); setC1(m1);
}

// Валідація. Якщо значення < 0, викидаємо виняток.
void Money::set500(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b500 = v; }
void Money::set200(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b200 = v; }
void Money::set100(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b100 = v; }
void Money::set50(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b50 = v; }
void Money::set20(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b20 = v; }
void Money::set10(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b10 = v; }
void Money::set5(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b5 = v; }
void Money::set2(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b2 = v; }
void Money::set1(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); b1 = v; }
void Money::setC50(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c50 = v; }
void Money::setC25(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c25 = v; }
void Money::setC10(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c10 = v; }
void Money::setC5(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c5 = v; }
void Money::setC2(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c2 = v; }
void Money::setC1(int v) { if (v < 0) throw std::invalid_argument("Cannot be negative"); c1 = v; }

long long Money::GetTotalKopiikas() const {
    return (b500 * 50000LL) + (b200 * 20000LL) + (b100 * 10000LL) + (b50 * 5000LL) +
        (b20 * 2000LL) + (b10 * 1000LL) + (b5 * 500LL) + (b2 * 200LL) + (b1 * 100LL) +
        (c50 * 50LL) + (c25 * 25LL) + (c10 * 10LL) + (c5 * 5LL) + (c2 * 2LL) + c1;
}

void Money::SetOptimalFromKopiikas(long long total) {
    if (total < 0) total = 0;
    b500 = total / 50000; total %= 50000;
    b200 = total / 20000; total %= 20000;
    b100 = total / 10000; total %= 10000;
    b50 = total / 5000; total %= 5000;
    b20 = total / 2000; total %= 2000;
    b10 = total / 1000; total %= 1000;
    b5 = total / 500; total %= 500;
    b2 = total / 200; total %= 200;
    b1 = total / 100; total %= 100;
    c50 = total / 50; total %= 50;
    c25 = total / 25; total %= 25;
    c10 = total / 10; total %= 10;
    c5 = total / 5; total %= 5;
    c2 = total / 2; total %= 2;
    c1 = total;
}

void Money::Read() {
    int v;
    std::cout << "--- Entering Bills ---\n";
    std::cout << "  500 UAH: "; std::cin >> v; set500(v);
    std::cout << "  200 UAH: "; std::cin >> v; set200(v);
    std::cout << "  100 UAH: "; std::cin >> v; set100(v);
    std::cout << "   50 UAH: "; std::cin >> v; set50(v);
    std::cout << "   20 UAH: "; std::cin >> v; set20(v);
    std::cout << "   10 UAH: "; std::cin >> v; set10(v);
    std::cout << "    5 UAH: "; std::cin >> v; set5(v);
    std::cout << "    2 UAH: "; std::cin >> v; set2(v);
    std::cout << "    1 UAH: "; std::cin >> v; set1(v);

    std::cout << "--- Entering Coins ---\n";
    std::cout << "  50 kop: "; std::cin >> v; setC50(v);
    std::cout << "  25 kop: "; std::cin >> v; setC25(v);
    std::cout << "  10 kop: "; std::cin >> v; setC10(v);
    std::cout << "   5 kop: "; std::cin >> v; setC5(v);
    std::cout << "   2 kop: "; std::cin >> v; setC2(v);
    std::cout << "   1 kop: "; std::cin >> v; setC1(v);
}

std::string Money::toString() const {
    long long total = GetTotalKopiikas();
    std::stringstream ss;
    ss << total / 100 << "," << std::setfill('0') << std::setw(2) << total % 100 << " UAH";
    return ss.str();
}

void Money::Display() const {
    std::cout << toString() << std::endl;
}

Money Money::Add(const Money& other) const {
    Money result;
    result.SetOptimalFromKopiikas(this->GetTotalKopiikas() + other.GetTotalKopiikas());
    return result;
}

Money Money::Subtract(const Money& other) const {
    long long t1 = this->GetTotalKopiikas();
    long long t2 = other.GetTotalKopiikas();
    if (t2 > t1) throw std::logic_error("Result cannot be negative");
    Money result;
    result.SetOptimalFromKopiikas(t1 - t2);
    return result;
}

double Money::DivideSums(const Money& other) const {
    long long t2 = other.GetTotalKopiikas();
    if (t2 == 0) throw std::logic_error("Division by zero sum");
    return (double)this->GetTotalKopiikas() / t2;
}

Money Money::DivideFraction(double fraction) const {
    if (fraction == 0.0) throw std::logic_error("Division by zero");
    Money result;
    result.SetOptimalFromKopiikas(this->GetTotalKopiikas() / fraction);
    return result;
}

Money Money::MultiplyFraction(double fraction) const {
    Money result;
    result.SetOptimalFromKopiikas(this->GetTotalKopiikas() * fraction);
    return result;
}

bool Money::IsEqual(const Money& other) const { return this->GetTotalKopiikas() == other.GetTotalKopiikas(); }
bool Money::IsGreater(const Money& other) const { return this->GetTotalKopiikas() > other.GetTotalKopiikas(); }
bool Money::IsLess(const Money& other) const { return this->GetTotalKopiikas() < other.GetTotalKopiikas(); }