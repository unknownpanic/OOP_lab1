#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;


struct Price {
    int hryvnia;
    int kopiykas;

    Price() : hryvnia(0), kopiykas(0) {}
    Price(int h, int k) : hryvnia(h), kopiykas(k) {
        normalize();
    }

    void normalize() {
        if (kopiykas >= 100) {
            hryvnia += kopiykas / 100;
            kopiykas %= 100;
        }
    }

    Price operator+(const Price& other) const {
        Price result(hryvnia + other.hryvnia, kopiykas + other.kopiykas);
        result.normalize();
        return result;
    }

    Price operator*(double multiplier) const {
        double totalKop = (hryvnia * 100 + kopiykas) * multiplier;
        int roundedTotal = static_cast<int>(round(totalKop));
        Price result(roundedTotal / 100, roundedTotal % 100);
        return result;
    }

    Price roundToNationalBank() const {
        Price newPrice(hryvnia, kopiykas);
        int remainder = newPrice.kopiykas % 10;
        if (remainder < 5)
            newPrice.kopiykas -= remainder;
        else
            newPrice.kopiykas += (10 - remainder);

        if (newPrice.kopiykas >= 100) {
            newPrice.hryvnia += newPrice.kopiykas / 100;
            newPrice.kopiykas %= 100;
        }
        return newPrice;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Price total;

    cout << "enter data in the format: hryvnia kopiykas quantity (e.g.: 19 89 3)." << endl;
    cout << "to finish app, use an incorrect format." << endl;

    int h, k, quantity;
    while (cin >> h >> k >> quantity) {
        Price itemPrice(h, k);
        Price cost = itemPrice * quantity;
        total = total + cost;
    }

    Price roundedTotal = total.roundToNationalBank();

    cout << "\ntotal bill amount: "
        << total.hryvnia << " hryvnia " << total.kopiykas << " kopiykas" << endl;
    cout << "amount due (rounded): "
        << roundedTotal.hryvnia << " Hryvnia " << roundedTotal.kopiykas << " kopiykas" << endl;

    return 0;
}
