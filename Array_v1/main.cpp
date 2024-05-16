#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array<int> vet(10), vet2(5);

    for(size_t j{0}; j < vet.size(); ++j) {
        vet[j] = 2 * j;
    }

    cout << "vet1: ";
    for(size_t i{0}; i < vet.size(); ++i) {
        cout << vet[i] << " ";
    }
    cout << endl;

    cout << "vet2: ";
    for(size_t i{0}; i < vet2.size(); ++i) {
        cout << vet2[i] << " ";
    }
    cout << endl;

    //vet2 = vet;
    vet.swap(vet2);

    cout << "vet1: ";
    for(size_t i{0}; i < vet.size(); ++i) {
        cout << vet[i] << " ";
    }
    cout << endl;
    cout << "vet2: ";
    for(size_t i{0}; i < vet2.size(); ++i) {
        cout << vet2[i] << " ";
    }
    cout << endl;

    if(vet == vet2) {
        cout << "vet1 == vet2\n";
    }
    else {
        cout << "vet1 != vet2\n";
    }
}