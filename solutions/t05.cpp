/*
 * Author: Tommaso Chiti
 */

#include <iostream>
#include <cstring>
#define BANNER "*** Rubrica ***\n 1 - Visualizza rubrica\n 2 - Inserisci contatto\n 3 - Cancella contatto\n 4 - Esci"
#define safeCin(arg, placeholder, action)                                                   \
    while(!valid) {                                                                         \
        cout << "Inserisci il " << placeholder << " del contatto da " << action << ": ";    \
        cin.getline(arg, 32);                                                               \
        if(cin.fail()) {                                                                    \
            valid = false;                                                                  \
            cout << "Errore: l'input' supera 32 caratteri!" << endl;                        \
            cin.clear();                                                                    \
            cin.ignore(1000, '\n');                                                         \
        } else if (arg[0] == '\0') {                                                        \
            valid = false;                                                                  \
            cout << "Errore: non hai inserito niente!" << endl;                             \
        } else valid = true;                                                                \
};                                                                                          \

using namespace std;

struct person {
    char name[32];
    char surname[32];
    char phone_number[32];
};

int main() {

    int menu_selector, cursor = 0;
    person phone_book[100];

    do {

        person new_person{};

        cout << BANNER << endl;
        cin >> menu_selector;
        cin.ignore();

        switch (menu_selector) {
            case 1:
                if (!cursor)
                    cout << "Rubrica vuota, non c'e' niente da visualizzare!" << endl;
                else
                    for (int i = 0; i < cursor; i++)
                        cout << phone_book[i].name << " " << phone_book[i].surname << " " << phone_book[i].phone_number << endl;
                break;
            case 2: {
                bool valid = false;
                safeCin(new_person.name, "nome", "inserire")
                valid = false;
                safeCin(new_person.surname, "cognome", "inserire")
                valid = false;
                safeCin(new_person.phone_number, "numero di telefono", "inserire")
                phone_book[cursor] = new_person;
                cursor++;
                cout << "Contatto aggiunto!" << endl;
                break;
            }
            case 3: {
                if (!cursor)
                    cout << "Rubrica vuota, non c'e' niente da cancellare!" << endl;
                else {
                    bool valid = false;
                    safeCin(new_person.name, "nome", "cancellare")
                    valid = false;
                    safeCin(new_person.surname, "cognome", "cancellare")
                    for (int i = 0; i < cursor; i++)
                        if (!strcmp(new_person.name, phone_book[i].name) && !strcmp(new_person.surname, phone_book[i].surname)) {
                            for (int j = i; j < cursor; j++)
                                phone_book[j] = phone_book[j + 1];
                            cursor--;
                            cout << "Contatto cancellato!" << endl;
                            break;
                        } else if (i == cursor - 1)
                            cout << "Contatto non trovato!" << endl;
                }
                break;
            }
            case 4:
                cout << "Addio!" << endl;
                break;
            default:
                break;
        }

    } while (menu_selector != 4);
    return 0;
}