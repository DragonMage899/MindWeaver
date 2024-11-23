#include "MidTax.h"

MidTax::MidTax()
{
    taxRate = 0.1;
    type = "mid";
}

double MidTax::calculateTax(double revenue)
{
    return revenue*taxRate;
}