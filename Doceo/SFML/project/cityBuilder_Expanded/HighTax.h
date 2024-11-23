#ifndef HIGHTAX
#define HIGHTAX

#include "TaxPolicy.h"

class HighTax : public TaxPolicy
{
public:
    HighTax();
    virtual double calculateTax(double Revenue);


};

#endif