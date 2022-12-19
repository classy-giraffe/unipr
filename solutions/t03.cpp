/*
 * Author: Tommaso Chiti
 */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int bits, bit, choice;

	do {
		cout << "Bits: ";
		cin >> bits;
		if (bits < 2)
			cout << "Errore!" << endl;
	} while (bits < 2);

	int bits_array[bits], bits_iterator = bits;

	while (bits > 0) {
		cout << "Inserisci il bit nella posizione " << bits - 1 << ": ";
		cin >> bit;
		if (bit != 0 && bit != 1)
			cout << "Errore!" << endl;
		else {
			bits_array[bits_iterator - bits] = bit;
			bits--;
		}
	}

	cout << "Operazione: \n";
	cout << "0 - Stampa binario: \n"
			"1 - Converti in decimale: \n"
			"2 - Calcola opposto: \n";

	do {
		cout << "Scelta: ";
		cin >> choice;
		if (choice < 0 || choice > 2)
			cout << "Errore!" << endl;
	} while (choice < 0 || choice > 2);

	switch(choice) {
		case 0:
			cout << "Numero binario: ";
			for (int i = 0; i < bits_iterator; i++)
				cout << bits_array[i];
			break;
		case 1: {
			double decimal = 0;
			for (int i = 0; i < bits_iterator; i++)
				decimal += bits_array[i] * pow (2, bits_iterator - i - 1);
			if (bits_array[0] != 0)
				decimal = -decimal;
			cout << "Numero decimale: " << decimal;
			break;
		}
		case 2: {
			bool overflow = false;
			for (int i = 0; i < bits_iterator; i++)
				if (bits_array[0] && bits_array[i] == 0) {
					overflow = true;
				}
			if (overflow) {
				cout << "Overflow!";
				break;
			}
			for (int i = 0; i < bits_iterator; i++)
				bits_array[i] = !bits_array[i];
			for (int i = bits_iterator - 1; i >= 0; i--)
				if (bits_array[i] == 0) {
					bits_array[i] = 1;
					break;
				} else
					bits_array[i] = 0;
			cout << "Opposto: ";
			for (int i = 0; i < bits_iterator; i++)
				cout << bits_array[i];
			break;
		}
		default:
			break;
	}
	return 0;
}