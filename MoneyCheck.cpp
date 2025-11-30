#include <iostream>
#include "MoneyLib.h"
#include "Windows.h"

using namespace std;
using namespace MoneyOperations;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Money m1(150, 75); 
    Money m2(85, 30);  
    Money m3(235.50);   

    cout << "Початкові суми:" << endl;
    cout << "m1 = "; m1.print();
    cout << "m2 = "; m2.print();
    cout << "m3 = "; m3.print();
    cout << endl;

    cout << "Арифметичні операції:" << endl;
    Money sum = m1 + m2;
    cout << "m1 + m2 = "; sum.print();

    Money diff = m1 - m2;
    cout << "m1 - m2 = "; diff.print();

    Money multiplied = m1 * 1.5;
    cout << "m1 * 1.5 = "; multiplied.print();

    Money divided = m3 / 2.0;
    cout << "m3 / 2.0 = "; divided.print();

    double ratio = m1 / m2;
    cout << "m1 / m2 = " << ratio << endl;
    cout << endl;

    cout << "Порівняння:" << endl;
    cout << "m1 == m2: " << (m1 == m2 ? "так" : "ні") << endl;
    cout << "m1 != m2: " << (m1 != m2 ? "так" : "ні") << endl;
    cout << "m1 > m2: " << (m1 > m2 ? "так" : "ні") << endl;
    cout << "m1 < m3: " << (m1 < m3 ? "так" : "ні") << endl;

    return 0;
}
