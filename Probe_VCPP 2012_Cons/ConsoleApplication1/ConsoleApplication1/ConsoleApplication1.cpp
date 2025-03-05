#include <iostream>
#include <windows.h>
#include "price.h"

using namespace std;

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

    Price roundedTotal = roundToNationalBank(total);

    cout << "\ntotal bill amount: "
        << total.hryvnia << " hryvnia " << total.kopiykas << " kopiykas" << endl;
    cout << "amount due (rounded): "
        << roundedTotal.hryvnia << " Hryvnia " << roundedTotal.kopiykas << " kopiykas" << endl;

    return 0;
}
