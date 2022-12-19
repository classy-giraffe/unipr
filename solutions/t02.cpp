/*
 * Author: Tommaso Chiti
 */

#include "iostream"
#include "cmath"
using namespace std;

int main() {
    int n;

    while (true) {
        cout << "Inserire un valore intero ( > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Input errato." << endl;
            continue;
        }
        break;
    }

    cout << endl;

    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < n; j++)
            if (j >= abs(n - i))
                cout << " *";
            else
                cout << "  ";
        cout << endl;
    }

    return 0;
}