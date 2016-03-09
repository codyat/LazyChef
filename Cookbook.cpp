#include "Cookbook.h"

Cookbook::Cookbook()
{
  ReadIn("cookbook.ini");
}

void Cookbook::print()
{
  for(unsigned i = 0; i < recipes.size(); i++)
  {
    cout << "Recipe " << i+1 << ": " << recipes[i]->GetName() << endl;
    recipes[i]->print();
    cout << endl;
  }
}

void Cookbook::ReadIn(string f)
{
  fstream cbook, rec;
  string recipeFilename;
  Recipe* recipe;

  cbook.open(f.c_str());
  while (cbook >> recipeFilename && recipeFilename != "")
  {
    recipe = new Recipe("recipes/" + recipeFilename);
    recipes.push_back(recipe);
  }
  cbook.close();
}
