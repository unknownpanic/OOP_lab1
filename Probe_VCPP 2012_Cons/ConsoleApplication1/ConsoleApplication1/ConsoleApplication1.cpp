#include <iostream>
#include <windows.h>
#include "price.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Price total = {0, 0};

    cout << "Enter data in the format: hryvnia kopiykas quantity (e.g.: 19 89 3)." << endl;
    cout << "To finish, use an incorrect format." << endl;

    int h, k, quantity;
    while (cin >> h >> k >> quantity) {
        Price itemPrice = createPrice(h, k);
        Price cost = multiplyPrice(itemPrice, quantity);
        total = addPrices(total, cost);
    }

    Price roundedTotal = roundToNationalBank(total);

    cout << "\nTotal bill amount: "
         << total.hryvnia << " hryvnia " << total.kopiykas << " kopiykas" << endl;
    cout << "Amount due (rounded): "
         << roundedTotal.hryvnia << " hryvnia " << roundedTotal.kopiykas << " kopiykas" << endl;

    return 0;
}
