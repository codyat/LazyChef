#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Fraction
{
  private:
    int whole;
    int numerator;
    int denominator;
  public:
    Fraction();
    Fraction(int w, int n, int d);
    void print();
};

#endif
