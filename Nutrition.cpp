#include "Nutrition.h"

Nutrition::Nutrition()
{}

Nutrition::Nutrition(unsigned int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    s = "ingredients/" + s + ".nutrient";
    fstream f(s.c_str());

    // TODO: Complete the parser logic for each nutrient
    //

    // disregard first couple lines
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 
    getline(f, s);
    cout << "s = " << s << "***" << endl; 

    f.close();

exit (0);

    while (getline(f, s) && s != "")
    {
        
    }
    //
    //
    
    f.close();
}

void Nutrition::printBasic(string s)
{
    for(unsigned int i = 0 ; i < 12; i++)
    {
        if(data.find(BASIC[i]) != data.end())
        {
            cout << "        " << BASIC[i] << " = " << data[BASIC[i]][s] << endl;
        } 
    }
}
