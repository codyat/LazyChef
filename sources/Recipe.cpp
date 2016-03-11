#include "Recipe.h"
#include <ctype.h>

Ingredient* parse_ingredient(string);
void debug(int, int, int, string, string);

Recipe::Recipe()
{
}

void Recipe::print()
{
    for(unsigned i = 0; i < ingredients.size(); i++)
    {
        cout << "    Ingredient " << i+1 << ": ";  
        ingredients[i]->print();
    }
    cout << endl;
    for(unsigned i = 0; i < directions.size(); i++)
        cout << "    Step " << i+1 << ": " << directions[i] << endl;
}

Recipe::Recipe(string f)
{
    fstream file(f.c_str());
    string s;

    // get the name of the recipe  
    while(file >> s && s != "[NAME]");
    //file >> name;
    getline(file, name);
    getline(file, name);

    // parse until the ingredients  
    while(file >> s && s != "[INGREDIENTS]");

    // get the list of ingredients
    getline(file, s);
    getline(file, s);
  
    while(s != "[DIRECTIONS]")
    {
        ingredients.push_back(parse_ingredient(s));
        getline(file, s);
    }
  
    // get the list of directions
    getline(file, s);
    while(s != "[PREPTIME]")
    {
        directions.push_back(s);
        getline(file, s);
    }

    // get the prep time
    file >> prepTime;
 
    // get the servings
    while(file >> s && s != "[SERVINGS]");
    file >> servings;

    file.close();
}

Ingredient* parse_ingredient(string s)
{
    stringstream ss(s);
    int w(0), n(0), d(1);
    string unit("");

    // goal is to differentiate between 
    // 1 : tortilla
    // 1 1/2 : banana
    // 1/2 : apple
    // 1 cup : beans
    // 1 1/2 tbsp : olive oil
    // 3/4 cup : quinoa

    // split at :
    string amount, material;
    amount = s.substr(0, s.find(" : "));
    material = s.substr(s.find(" : ") + 3);
  
    // parse the amount
    // if slash was found, then fraction exists
    if(amount.find("/") == -1) // no slash, no fraction
    {
        if(amount.find(" ") == -1) // no units
            w = atoi(amount.c_str());
        else // yes units
        {        
            w = atoi(amount.substr(0, amount.find(" ")).c_str());
            unit = amount.substr(amount.find(" ") + 1);
        }
    }
    else // yes slash, yes fraction
    {
        // check for preceding whole number 
        if(amount.find(" ") != -1 && amount.find(" ") < amount.find("/")) // whole number exists
        {
            w = atoi(amount.substr(0, amount.find(" ")).c_str());
            amount = amount.substr(amount.find(" ") + 1);
        }
        n = atoi(amount.substr(0, amount.find("/")).c_str());
        d = atoi(amount.substr(amount.find("/") + 1).c_str());
        if (amount.find(" ") != -1) // yes units
            unit = amount.substr(amount.find(" ") + 1);
    }

////cout << "    return new Ingredient("<<material<<", "<<w<<", "<<n<<", "<<d<<", "<<unit<<");" << endl;
    return new Ingredient(material, w, n, d, unit);
}

void debug(int w, int n, int d, string u, string m)
{
    cout << "************************************" << endl
         << "w = " << w << endl
         << "n = " << n << endl
         << "d = " << d << endl
         << "u = " << u << endl
         << "m = " << m << endl
         << "************************************" << endl; 
}
