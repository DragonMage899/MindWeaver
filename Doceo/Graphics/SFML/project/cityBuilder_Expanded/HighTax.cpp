#include "HighTax.h"

HighTax::HighTax()
{
    taxRate = 0.25;
    type = "high";
}

double HighTax::calculateTax(double revenue)
{
    return revenue*taxRate;
}