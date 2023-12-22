#pragma once
#include "Barco.h"

class Destructor : public Barco
{
public:
    Destructor() {}
    void propio() const override;
protected:
};