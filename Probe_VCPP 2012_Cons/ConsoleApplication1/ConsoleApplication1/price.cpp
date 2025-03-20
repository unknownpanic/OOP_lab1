#include "price.h"
#include <cmath>

void normalize(int& hryvnia, short& kopiykas) {
    if (kopiykas >= 100) {
        hryvnia += kopiykas / 100;
        kopiykas %= 100; // Перетворення копійок у гривні, якщо копійок більше 100
    }
}

void addPrices(Price& p1, const Price& p2) {
    p1.hryvnia += p2.hryvnia;
    p1.kopiykas += p2.kopiykas;
    normalize(p1.hryvnia, p1.kopiykas);
}

void multiplyPrice(Price& p, int multiplier) {
    int totalKop = (p.hryvnia * 100 + p.kopiykas) * multiplier;
    p.hryvnia = totalKop / 100;
    p.kopiykas = totalKop % 100;
    normalize(p.hryvnia, p.kopiykas);
}

void roundToNationalBank(int& hryvnia, short& kopiykas) {
    int remainder = kopiykas % 10;
    if (remainder < 5)
        kopiykas -= remainder;
    else
        kopiykas += (10 - remainder);

    normalize(hryvnia, kopiykas); // Заокруглення копійок за правилами Нацбанку
}