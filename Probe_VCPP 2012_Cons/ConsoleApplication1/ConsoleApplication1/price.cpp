#include "price.h"
#include <cmath>

Price createPrice(int h, int k) {
    Price price = {h, k};
    normalize(price);
    return price;
}

void normalize(Price& price) {
    if (price.kopiykas >= 100) {
        price.hryvnia += price.kopiykas / 100;
        price.kopiykas %= 100;
    }
}

Price addPrices(const Price& a, const Price& b) {
    Price result = {a.hryvnia + b.hryvnia, a.kopiykas + b.kopiykas};
    normalize(result);
    return result;
}

Price multiplyPrice(const Price& price, double multiplier) {
    double totalKop = (price.hryvnia * 100 + price.kopiykas) * multiplier;
    int roundedTotal = static_cast<int>(round(totalKop));
    return createPrice(roundedTotal / 100, roundedTotal % 100);
}

Price roundToNationalBank(const Price& price) {
    Price newPrice = price;
    int remainder = newPrice.kopiykas % 10;

    if (remainder < 5)
        newPrice.kopiykas -= remainder;
    else
        newPrice.kopiykas += (10 - remainder);

    normalize(newPrice);
    return newPrice;
}
