/*
 * Author: Tommaso Chiti
 */

#include <iostream>
using namespace std;
const int MAX = 1000;

int main() {

    int *A[MAX];
    int allocated_variables = 0, unique_variables = 0, i, x, count[MAX];

    cout << "Inserire un numero: ";
    cin >> x;

    while (x >= 0) {
        bool found = false;

        for (i = 0; i < allocated_variables; i++)
            if (*A[i] == x) {
                found = true;
                break;
            }

        if (!found) {
            A[allocated_variables] = new int(x);
            count[allocated_variables] = 1;
            allocated_variables++;
            unique_variables++;
        } else {
            A[allocated_variables] = A[i];
            count[allocated_variables] = count[i] + 1;
            allocated_variables++;
        }

        cout << "Inserire un numero: ";
        cin >> x;
    }

    cout << "Allocate " << unique_variables << " variabili." << endl;
    for (int j = 0; j < allocated_variables; j++)
        cout << *A[j] << " ";

    cout << endl;

    for (int j = 0; j < allocated_variables; j++)
        if (count[j] == 1)
            delete A[j];

    return 0;
}