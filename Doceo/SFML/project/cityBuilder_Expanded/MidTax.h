#ifndef MIDTAX
#define MIDTAX

#include "TaxPolicy.h"

class MidTax : public TaxPolicy
{
public:
    MidTax();
    virtual double calculateTax(double Revenue);


};

#endif