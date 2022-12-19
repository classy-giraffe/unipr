/*
 * Author: Tommaso Chiti
 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void separa(const char s[], char alpha[], char digit[], int& j, int& k) {
    for (int i = 0; i < strlen(s); i++)
        if (isalpha(s[i])) {
            alpha[j] = s[i];
            j++;
        } else if (isdigit(s[i])) {
            digit[k] = s[i];
            k++;
        }
}

int main() {
    int digit_count = 0, alpha_count = 0;
    char str[101], SAlpha[101], SNum[101];
    bool failed = false;

    while(!failed) {
        cout << "Inserisci una stringa: ";
        cin.getline(str, 101);
        if (cin.fail()) {
            cout << "Stringa troppo lunga, riprova." << endl;
            failed = false;
            cin.clear();
            cin.ignore(1000, '\n');
        } else failed = true;
    }

    separa(str, SAlpha, SNum, alpha_count, digit_count);

    cout << "Caratteri alfabetici: " << endl;
    for (int i = 0; i < alpha_count; i++)
        cout << SAlpha[i];

    cout << endl;

    cout << "Caratteri numerici: " << endl;
    for (int i = 0; i < digit_count; i++)
        cout << SNum[i];

    return 0;
}
