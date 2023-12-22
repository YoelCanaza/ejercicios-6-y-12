#pragma once
class Barco
{
public:
    Barco();
    virtual ~Barco(); // Necesitaremos un destructor virtual en la clase base si vamos a borrar objetos a través de punteros base
    virtual void propio() const;
    void ver();
    
    static void mostrarNumeroBarcos();
protected:
    static int numeroBarcos;
};