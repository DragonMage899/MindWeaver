#ifndef LOWTAX
#define LOWTAX

#include "TaxPolicy.h"

class LowTax : public TaxPolicy
{
public:
    LowTax();
    virtual double calculateTax(double Revenue);


};

#endif