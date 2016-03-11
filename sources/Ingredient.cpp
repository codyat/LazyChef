#include "Ingredient.h"

int translateNDBNO(string);
void initTable();

Ingredient::Ingredient(){}
Ingredient::Ingredient(string m, int w, int n, int d, string u)
:name(m), units(u)
{
    // Never load more than once 
    if (!isTableLoaded)
    {
        initTable();
        isTableLoaded = true;
    }

    // Cross reference the ingredient name on the translation table to 
    // get the NDBNO of the ingredient. 
    NDBNO = translateNDBNO(m);
    amount = new Fraction(w, n, d);

    // Create the nutritional info
    nutritionalValue = new Nutrition(NDBNO);
}

void Ingredient::print() 
{
    amount->print();
    if(units.length() > 1)
        cout << units << " of ";
    cout << name << endl;
//         << " *** NDBNO = " << NDBNO << " *** " << endl;
    nutritionalValue->printBasic(units);
    
}

void initTable()                                                                                                                        
{            
    // Load all info from the ingredient table   
    fstream f ("TranslationTable.txt");                                                                                                 
    string s;                                                                                                                           
    string name;                                                                                                                        
    unsigned number;                                                                                                                    
                                                                                                                                        
    while(getline(f, s) && s != "")                                                                                                     
    {                                                                                                                                   
        name = s.substr(0, s.find(" : "));                                                                                              
        number = (unsigned) (atoi(s.substr(s.find(" : ") + 3).c_str()));                                                                
                                                                                                                                        
        TranslationTable.insert(pair<string, unsigned> (name, number));                                                                 
    }  
 
    // Never leave the File stream open    
    f.close();
}

int translateNDBNO(string s)
{
    return TranslationTable[s];
}

