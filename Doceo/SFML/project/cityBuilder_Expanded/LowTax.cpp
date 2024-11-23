#include "LowTax.h"

LowTax::LowTax()
{
    taxRate = 0.05;
    type = "low";
}

double LowTax::calculateTax(double revenue)
{
    return revenue*taxRate;
}