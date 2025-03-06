#include "price.h"
#include <cmath>

void normalize(int& hryvnia, int& kopiykas) {
    if (kopiykas >= 100) {
        hryvnia += kopiykas / 100;
        kopiykas %= 100;
    }
}

void addPrices(int h1, int k1, int h2, int k2, int& resultH, int& resultK) {
    resultH = h1 + h2;
    resultK = k1 + k2;
    normalize(resultH, resultK);
}

void multiplyPrice(int h, int k, double multiplier, int& resultH, int& resultK) {
    double totalKop = (h * 100 + k) * multiplier;
    int roundedTotal = static_cast<int>(round(totalKop));
    resultH = roundedTotal / 100;
    resultK = roundedTotal % 100;
}

void roundToNationalBank(int& hryvnia, int& kopiykas) {
    int remainder = kopiykas % 10;
    if (remainder < 5)
        kopiykas -= remainder;
    else
        kopiykas += (10 - remainder);

    normalize(hryvnia, kopiykas);
}
