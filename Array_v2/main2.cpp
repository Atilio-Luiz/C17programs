#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array<int> vet(10);

    int counter = 1;
    for(auto it = vet.begin(); it != vet.end(); ++it) {
        *it = counter;
        counter++;
    }

    // imprime na tela usando iteradores
    for(auto it = vet.begin(); it != vet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // imprime na tela usando for-each (usa iteradores nos bastidores)
    for(int& e : vet) {
        cout << e << " ";
    }
    cout << endl;

}