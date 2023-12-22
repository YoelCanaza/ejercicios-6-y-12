#include <iostream>

using namespace std;

class Barco
{
public:
    Barco();
    virtual ~Barco();
    virtual void propio() const = 0;
    void ver();
    
    static int obtenerNumeroBarcos();
protected:
    static int numeroBarcos;
};

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

int Barco::obtenerNumeroBarcos()
{
    return numeroBarcos;
}

void Barco::ver()
{
    cout << "Se ha llamado a la función ver()" << endl;
}



class Submarino : public Barco
{
public:
    Submarino() {}
    void propio() const override;

protected:

};

void Submarino::propio() const
{
    cout << "SUBMARINO: Se ha llamado a la función propio() sobreescrita por la clase derivada Submarino" << endl;
}



class Destructor : public Barco
{
public:
    Destructor() {}
    void propio() const override;
protected:
};

void Destructor::propio() const{
    cout << "DESTRUCTOR: Se ha llamado a la función propio() sobreescrita por la clase derivada Destructor" << endl;
}

int main()
{
    // 1.b: Supongamos que la asignatura del método propio es la siguiente:
    // virtual void Barco::propio()=0;
    /*
    Barco* f[] = {new Barco(), new Submarino()};
    f[0]->propio();
    f[0]->ver();
    f[1]->propio();
    f[1]->ver();
    cout << endl;
    */
}