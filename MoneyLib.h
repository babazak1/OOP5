#pragma once
namespace MoneyOperations {
    class Money {
    private:
        long hryvnias;          
        unsigned char kopiykas; 

        void normalize();

    public:
        Money();
        Money(long hryv, unsigned char kop);
        Money(double amount);

        long getHryvnias() const;
        unsigned char getKopiykas() const;
        double toDouble() const;

        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        Money operator*(double multiplier) const;
        Money operator/(double divisor) const;
        double operator/(const Money& other) const; 

        bool operator==(const Money& other) const;
        bool operator!=(const Money& other) const;
        bool operator<(const Money& other) const;
        bool operator>(const Money& other) const;
        bool operator<=(const Money& other) const;
        bool operator>=(const Money& other) const;

        void print() const;
    };
}
