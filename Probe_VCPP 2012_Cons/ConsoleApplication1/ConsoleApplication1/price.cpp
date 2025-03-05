#include "price.h"

Price::Price() : hryvnia(0), kopiykas(0) {}

Price::Price(int h, int k) : hryvnia(h), kopiykas(k) {
    normalize();
}

void Price::normalize() {
    if (kopiykas >= 100) {
        hryvnia += kopiykas / 100;
        kopiykas %= 100;
    }
}

Price operator+(const Price& a, const Price& b) {
    Price result(a.hryvnia + b.hryvnia, a.kopiykas + b.kopiykas);
    result.normalize();
    return result;
}

Price operator*(const Price& price, double multiplier) {
    double totalKop = (price.hryvnia * 100 + price.kopiykas) * multiplier;
    int roundedTotal = static_cast<int>(round(totalKop));
    return Price(roundedTotal / 100, roundedTotal % 100);
}

Price roundToNationalBank(const Price& price) {
    Price newPrice = price;
    int remainder = newPrice.kopiykas % 10;
    if (remainder < 5)
        newPrice.kopiykas -= remainder;
    else
        newPrice.kopiykas += (10 - remainder);

    newPrice.normalize();
    return newPrice;
}
