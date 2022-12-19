/*
 * Author: Tommaso Chiti
 */

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char first_word[101], second_word[101];
    while (true) {
        cout << "Inserire la prima parola: ";
        cin.getline(first_word, 101);
        if (!strcmp(first_word, "exit")) {
            cout << "Addio!" << endl;
            break;
        }
        cout << "Inserire la seconda parola: ";
        cin.getline(second_word, 101);
        if (!strcmp(first_word, second_word)) {
            cout << "Le due parole sono uguali." << endl;
            cout << "Reverse: " << strrev(first_word) << endl;
        } else if (!strncmp(first_word, second_word, strlen(first_word)) && !strncmp(first_word, second_word + strlen(second_word) - strlen(first_word), strlen(first_word))) {
            cout << "La parola " << first_word << " e' prefisso di " << second_word << endl;
            cout << "La parola " << first_word << " e' suffisso di " << second_word << endl;
        } else if (!strncmp(second_word, first_word, strlen(second_word)) && !strncmp(second_word, first_word + strlen(first_word) - strlen(second_word), strlen(second_word))) {
            cout << "La parola " << second_word << " e' prefisso di " << first_word << endl;
            cout << "La parola " << second_word << " e' suffisso di " << first_word << endl;
        } else if (strstr(second_word, first_word) == second_word)
            cout << "La parola " << first_word << " e' prefisso di " << second_word << endl;
        else if (strstr(first_word, second_word) == first_word)
            cout << "La parola " << second_word << " e' prefisso di " << first_word << endl;
        else if (strstr(second_word, first_word) == second_word + strlen(second_word) - strlen(first_word))
            cout << "La parola " << first_word << " e' suffisso di " << second_word << endl;
        else if (strstr(first_word, second_word) == first_word + strlen(first_word) - strlen(second_word))
            cout << "La parola " << second_word << " e' suffisso di " << first_word << endl;
    }
    return 0;
}
