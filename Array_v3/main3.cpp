#include <iostream>
#include <algorithm>
#include "Array.h"
using namespace std;

int main() {
    //vector<int> vet {1,2,7,4,5,7,3,7};
    //cout << count(vet.begin(), vet.end(), 7) << endl;

    Array<int> array(10);

    for(size_t i = 0; i < array.size(); ++i) { 
        array[i] = i;
    }

    for(auto& e : array) {
        cout << e << " ";
    }
    cout << endl;
    cout << count(array.begin(), array.end(), 6) << endl;
    
}