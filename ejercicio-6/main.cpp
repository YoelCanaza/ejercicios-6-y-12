#include <iostream>
#include "Barco.h"
#include "Submarino.h"
#include "Destructor.h"
#include "Comercial.h"

using namespace std;

int main()
{
    // 1.a Especifica qué pasará en los siguientes casos, suponiendo que propio() está sobreescrito en las clases derivadas
    // a
    Barco* a = new Barco();
    Barco::mostrarNumeroBarcos();
    a->propio();
    a->ver();
    cout << endl;
    // b
    Barco* b = new Submarino();
    Barco::mostrarNumeroBarcos();
    b->propio();
    b->ver();
    cout << endl;

    // c
    Barco* c[] = {new Barco(), new Submarino()};
    Barco::mostrarNumeroBarcos();
    c[0]->propio();
    c[1]->propio();
    c[0]->ver();
    cout << endl;

    // d
    Barco* d[] = {new Destructor(), new Submarino()};
    Barco::mostrarNumeroBarcos();
    d[0]->propio();
    d[1]->propio();
    cout << endl;

    // e: supongamos que añadimos ver() heredado del padre tanto en submarino como en destructor;

    Barco* e[] = {new Destructor(), new Submarino()};
    Barco::mostrarNumeroBarcos();
    ((Destructor *)e[0])->ver();
    ((Submarino *)e[1])->ver();
    e[0]->ver();
    e[1]->ver();
    cout << endl;

    delete a;
    delete b;

    for (int i = 0; i < 2; i++) {
        delete c[i];
    }

    for (int i = 0; i < 2; i++) {
        delete d[i];
    }

    for (int i = 0; i < 2; i++) {
        delete e[i];
    }


    // 1.b: Supongamos que la asignatura del método propio es la siguiente:
    // virtual void Barco::propio()=0;
    Barco* f[] = {new Barco(), new Submarino()};
    Barco::mostrarNumeroBarcos();
    f[0]->propio();
    f[0]->ver();
    f[1]->propio();
    f[1]->ver();
    cout << endl;
}
