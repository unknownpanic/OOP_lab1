#include <iostream>
#include <cmath>

struct Price {
    int hryvnia;
    int kopiykas;
};

void normalize(int& hryvnia, int& kopiykas);
void addPrices(int h1, int k1, int h2, int k2, int& resultH, int& resultK);
void multiplyPrice(int h, int k, double multiplier, int& resultH, int& resultK);
void roundToNationalBank(int& hryvnia, int& kopiykas);
