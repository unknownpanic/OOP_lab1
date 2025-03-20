#include <iostream>
#include <cmath>

struct Price {
    int hryvnia;
    short kopiykas;
};

void normalize(int& hryvnia, short& kopiykas);
void addPrices(Price& p1, const Price& p2);
void multiplyPrice(Price& p, int multiplier);
void roundToNationalBank(int& hryvnia, short& kopiykas);