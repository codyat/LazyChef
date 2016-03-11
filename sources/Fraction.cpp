#include "Fraction.h"

Fraction::Fraction()
:whole(0), numerator(0), denominator(1)
{
}

Fraction::Fraction(int w, int n, int d)
:whole(w), numerator(n), denominator(d)
{
}

void Fraction::print()
{
    if(whole > 0) 
        cout << whole << " ";
    if(denominator > 0)
    {
        if(numerator > 0) 
        {
            cout << numerator << "/" << denominator << " ";
        }
    }
    else
    {
        cout << "ERROR! Fix your recipe! Denominator is zero!" << endl;
        exit(1);
    }
}
