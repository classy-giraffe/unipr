/*
 * Author: Tommaso Chiti
 */

#include <iostream>
using namespace std;

void reverse(int arr[], int size) {
    if (size <= 1) return;
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
    reverse(arr + 1, size - 2);
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int elements_count;

    do {
        cout << "Quanti elementi vuoi inserire? ";
        cin >> elements_count;
        if (elements_count <= 0)
            cout << "Inserisci un numero di elementi >= 0!" << endl;
    } while (elements_count <= 0);

    int arr[elements_count];

    for (int i = 0; i < elements_count; i++) {
        cout << "Inserisci elemento: ";
        cin >> arr[i];
    }

    print(arr, elements_count);
    reverse(arr, elements_count);
    print(arr, elements_count);

    return 0;
}
