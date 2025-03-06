#include <iostream>
#include <cmath>

struct Price {
    int hryvnia;
    int kopiykas;
};

Price createPrice(int h, int k);
Price addPrices(const Price& a, const Price& b);
Price multiplyPrice(const Price& price, double multiplier);
Price roundToNationalBank(const Price& price);
void normalize(Price& price);
