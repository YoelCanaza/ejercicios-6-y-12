#pragma once
#include "Barco.h"

class Comercial : public Barco
{
public:
    Comercial() {}
    void propio() const override;
protected:
};