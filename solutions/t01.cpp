/*
 * Author: Tommaso Chiti
 */

#include <iostream>
using namespace std;

int main() {
    char a, b, c;
    cout << "Inserire tre caratteri: " << endl;
    cin >> a >> b >> c;
    a = (a >= 'a' && a <= 'z') ? (a >= 'x' && a <= 'z') ? a - 23 : a + 3 : '*';
    b = (b >= 'a' && b <= 'z') ? (b >= 'x' && b <= 'z') ? b - 23 : b + 3 : '*';
    c = (c >= 'a' && c <= 'z') ? (c >= 'x' && c <= 'z') ? c - 23 : c + 3 : '*';
    cout << "Cifrario di cesare: " << a << ' ' << b << ' ' << c << endl;
    return 0;
}