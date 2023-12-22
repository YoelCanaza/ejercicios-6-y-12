#include <iostream>
#include "Barco.h"

using namespace std;

int Barco::numeroBarcos = 0;

Barco::Barco()
{
    cout << "Creando barco... " << endl;
    numeroBarcos += 1;
}

Barco::~Barco()
{
    cout << "Eliminando barco... " << endl;
    numeroBarcos -= 1;
}

void Barco::propio() const
{
    cout << "BARCO: Se ha llamado a la función propio()" << endl;
}

void Barco::mostrarNumeroBarcos()
{
    cout << "El número de barcos totales es: " << numeroBarcos << endl;
}

void Barco::ver()
{
    cout << "Se ha llamado a la función ver()" << endl;
}