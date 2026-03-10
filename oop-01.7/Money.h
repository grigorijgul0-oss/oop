#pragma once
#include <iostream>
#include <string>

class Money {
private:
    
    unsigned int b500, b200, b100, b50, b20, b10, b5, b2, b1;
    
    unsigned int c50, c25, c10, c5, c2, c1;

    // Допоміжний метод для отримання загальної суми в копійках
    long long GetTotalKopiikas() const;

    // Допоміжний метод для перерахунку копійок у оптимальну кількість купюр/монет
    void SetOptimalFromKopiikas(long long total);

public:
    
    Money();

   
    void Init(int n500, int n200, int n100, int n50, int n20, int n10, int n5, int n2, int n1,
        int m50, int m25, int m10, int m5, int m2, int m1);

   
    void Read();
    void Display() const;
    std::string toString() const;

    // Методи доступу (Getters)
    unsigned int get500() const { return b500; }
    unsigned int get200() const { return b200; }
    unsigned int get100() const { return b100; }
    unsigned int get50() const { return b50; }
    unsigned int get20() const { return b20; }
    unsigned int get10() const { return b10; }
    unsigned int get5() const { return b5; }
    unsigned int get2() const { return b2; }
    unsigned int get1() const { return b1; }
    unsigned int getC50() const { return c50; }
    unsigned int getC25() const { return c25; }
    unsigned int getC10() const { return c10; }
    unsigned int getC5() const { return c5; }
    unsigned int getC2() const { return c2; }
    unsigned int getC1() const { return c1; }

    // Методи доступу (Setters) з жорсткою валідацією
    void set500(int v); void set200(int v); void set100(int v);
    void set50(int v); void set20(int v); void set10(int v);
    void set5(int v); void set2(int v); void set1(int v);
    void setC50(int v); void setC25(int v); void setC10(int v);
    void setC5(int v); void setC2(int v); void setC1(int v);

    
    Money Add(const Money& other) const;
    Money Subtract(const Money& other) const;
    double DivideSums(const Money& other) const;
    Money DivideFraction(double fraction) const;
    Money MultiplyFraction(double fraction) const;


    bool IsEqual(const Money& other) const;
    bool IsGreater(const Money& other) const;
    bool IsLess(const Money& other) const;
};