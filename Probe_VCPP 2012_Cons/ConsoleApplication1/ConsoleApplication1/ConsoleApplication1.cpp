#include <iostream>
#include <fstream>
#include <windows.h>
#include "price.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Price totalPrice = {0, 0}; // Ініціалізація загальної ціни
    string inputMethod;
    cout << "Enter 'file' to read from data.txt or 'console' to enter data manually: ";
    cin >> inputMethod;

    ifstream inputFile;
    bool useFile = (inputMethod == "file");
    if (useFile) {
        inputFile.open("data.txt");
        if (!inputFile) {
            cerr << "Error opening file. Switching to manual input." << endl;
            useFile = false;
        } else {
            cout << "Reading data from data.txt..." << endl;
        }
    }

    if (!useFile) {
        cout << "Enter data in the format: hryvnia kopiykas quantity (e.g.: 19 89 3)." << endl;
        cout << "To finish, use an incorrect format." << endl;
    }

    int h, quantity;
    short k;

    while ((useFile ? inputFile : cin) >> h >> k >> quantity) {
        Price itemPrice = {h, k};
        multiplyPrice(itemPrice, quantity);
        addPrices(totalPrice, itemPrice);
    }

    if (useFile) {
        inputFile.close();
    }

    Price roundedPrice = totalPrice;
    roundToNationalBank(roundedPrice.hryvnia, roundedPrice.kopiykas);

    cout << "\nTotal bill amount: " << totalPrice.hryvnia << " hryvnia " << totalPrice.kopiykas << " kopiykas" << endl;
    cout << "Amount due (rounded): " << roundedPrice.hryvnia << " hryvnia " << roundedPrice.kopiykas << " kopiykas" << endl;

    return 0;
}