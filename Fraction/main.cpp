#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction f, g;

    cout << "Digite a fracao f no formato a/b: ";
    cin >> f;
    cout << "Digite a fracao g no formato a/b: ";
    cin >> g;

    cout << "f = " << f << endl;
    cout << "g = " << g << endl;

    if(f < g) cout << f << " < " << g << endl;
    if(f > g) cout << f << " > " << g << endl;
    if(f <= g) cout << f << " <= " << g << endl;
    if(f >= g) cout << f << " >= " << g << endl;
    if(f == g) cout << f << " == " << g << endl;
    if(f != g) cout << f << " != " << g << endl;

    cout << "f - g = " << f - g << endl;
    cout << "f + g = " << f + g << endl;
    cout << "g - f = " << g - f << endl;
    cout << "g + f = " << g + f << endl;
    cout << "f - f = " << f - f << endl;

}