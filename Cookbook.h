#ifndef _COOKBOOK_H_
#define _COOKBOOK_H_

#include "Recipe.h"

class Cookbook
{
  private:
    vector<Recipe*> recipes;
    void ReadIn(string filename);
  public:
    Cookbook();
    void print();
};

#endif
