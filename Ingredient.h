#ifndef _INGREDIENT_H_
#define _INGREDIENT_H_

#include "Fraction.h"
#include "Nutrition.h"

using namespace std;

static map<string, unsigned> TranslationTable; 
static bool isTableLoaded = false;

class Ingredient
{
    private:
        string name;
        Fraction* amount;
        string units;
        Nutrition* nutritionalValue;
        unsigned int NDBNO;
    public:
        Ingredient();
        Ingredient(string f, int w, int n, int d, string u);
        void print();
        unsigned int getNDBNO(string s) { return NDBNO; } ;
};

#endif
