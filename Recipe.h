#ifndef _RECIPE_H_
#define _RECIPE_H_

#include "Ingredient.h"

class Recipe
{
  private:
    string name;
    vector<Ingredient*> ingredients;
    vector<string> directions;
    string prepTime;
    int servings;
  public:
    Recipe();
    Recipe(string f);
    void print();
    string GetName() { return name; };
    string GetPrepTime() { return prepTime; };
    int GetServings() { return servings; };
};

#endif
