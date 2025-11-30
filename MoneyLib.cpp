#include "MoneyLib.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace MoneyOperations {

    void Money::normalize() {
        if (kopiykas >= 100) {
            hryvnias += kopiykas / 100;
            kopiykas = kopiykas % 100;
        }

        if (kopiykas < 0) {
            hryvnias -= (-kopiykas / 100) + 1;
            kopiykas = 100 - (-kopiykas % 100);
        }

        if (hryvnias < 0 && kopiykas > 0) {
            hryvnias += 1;
            kopiykas = 100 - kopiykas;
        }
    }

    Money::Money() : hryvnias(0), kopiykas(0) {}

    Money::Money(long hryv, unsigned char kop)
        : hryvnias(hryv), kopiykas(kop) {
        normalize();
    }

    Money::Money(double amount) {
        hryvnias = static_cast<long>(amount);
        double kop = (amount - hryvnias) * 100;
        kopiykas = static_cast<unsigned char>(round(kop));
        normalize();
    }

    long Money::getHryvnias() const {
        return hryvnias;
    }

    unsigned char Money::getKopiykas() const {
        return kopiykas;
    }

    double Money::toDouble() const {
        return hryvnias + kopiykas / 100.0;
    }

    Money Money::operator+(const Money& other) const {
        long totalHryvnias = hryvnias + other.hryvnias;
        int totalKopiykas = kopiykas + other.kopiykas;

        Money result(totalHryvnias, static_cast<unsigned char>(totalKopiykas));
        result.normalize();
        return result;
    }

    Money Money::operator-(const Money& other) const {
        long totalHryvnias = hryvnias - other.hryvnias;
        int totalKopiykas = kopiykas - other.kopiykas;

        Money result(totalHryvnias, static_cast<unsigned char>(totalKopiykas));
        result.normalize();
        return result;
    }

    Money Money::operator*(double multiplier) const {
        double total = toDouble() * multiplier;
        return Money(total);
    }

    Money Money::operator/(double divisor) const {
        if (divisor == 0) {
            throw invalid_argument("Division by zero");
        }
        double total = toDouble() / divisor;
        return Money(total);
    }

    double Money::operator/(const Money& other) const {
        if (other.toDouble() == 0) {
            throw invalid_argument("Division by zero");
        }
        return toDouble() / other.toDouble();
    }

    bool Money::operator==(const Money& other) const {
        return hryvnias == other.hryvnias && kopiykas == other.kopiykas;
    }

    bool Money::operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool Money::operator<(const Money& other) const {
        if (hryvnias != other.hryvnias) {
            return hryvnias < other.hryvnias;
        }
        return kopiykas < other.kopiykas;
    }

    bool Money::operator>(const Money& other) const {
        return other < *this;
    }

    bool Money::operator<=(const Money& other) const {
        return !(other < *this);
    }

    bool Money::operator>=(const Money& other) const {
        return !(*this < other);
    }
    
    void Money::print() const {
        cout << hryvnias << ",";
        if (kopiykas < 10) {
            cout << "0";
        }
        cout << static_cast<int>(kopiykas) << " грн." << endl;
    }
}
