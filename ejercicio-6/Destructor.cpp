#include "Destructor.h"
#include <iostream>
using namespace std;

void Destructor::propio() const{
    cout << "DESTRUCTOR: Se ha llamado a la función propio() sobreescrita por la clase derivada Destructor" << endl;
}