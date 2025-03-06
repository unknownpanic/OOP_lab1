#include <iostream>
#include <windows.h>
#include "price.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int totalHryvnia = 0, totalKopiykas = 0;

    cout << "Enter data in the format: hryvnia kopiykas quantity (e.g.: 19 89 3)." << endl;
    cout << "To finish, use an incorrect format." << endl;

    int h, k, quantity;
    while (cin >> h >> k >> quantity) {
        int itemHryvnia, itemKopiykas;
        multiplyPrice(h, k, quantity, itemHryvnia, itemKopiykas);
        addPrices(totalHryvnia, totalKopiykas, itemHryvnia, itemKopiykas, totalHryvnia, totalKopiykas);
    }

    int roundedHryvnia = totalHryvnia, roundedKopiykas = totalKopiykas;
    roundToNationalBank(roundedHryvnia, roundedKopiykas);

    cout << "\nTotal bill amount: "
         << totalHryvnia << " hryvnia " << totalKopiykas << " kopiykas" << endl;
    cout << "Amount due (rounded): "
         << roundedHryvnia << " hryvnia " << roundedKopiykas << " kopiykas" << endl;

    return 0;
}
