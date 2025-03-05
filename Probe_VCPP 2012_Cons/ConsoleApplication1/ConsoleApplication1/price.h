#ifndef PRICE_H
#define PRICE_H
#include <iostream>
#include <cmath>

struct Price {
    int hryvnia;
    int kopiykas;

    Price();
    Price(int h, int k);
    void normalize();
};

Price operator+(const Price& a, const Price& b);
Price operator*(const Price& price, double multiplier);
Price roundToNationalBank(const Price& price);

#endif
