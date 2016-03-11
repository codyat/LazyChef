CC = g++

## Object files and executables
MAIN_OUT = LazyChef
COOKBOOK_OUT = Cookbook.o
RECIPE_OUT = Recipe.o
INGREDIENT_OUT = Ingredient.o
FRACTION_OUT = Fraction.o
NUTRITION_OUT = Nutrition.o

## Requirements for each command
MAIN_REQS = main.cpp $(COOKBOOK_OUT) $(RECIPE_OUT) $(INGREDIENT_OUT) $(FRACTION_OUT) $(NUTRITION_OUT)
COOKBOOK_REQS = Cookbook.h Cookbook.cpp
RECIPE_REQS = Recipe.h Recipe.cpp
INGREDIENT_REQS = Ingredient.h Ingredient.cpp
FRACTION_REQS = Fraction.h Fraction.cpp
NUTRITION_REQS = Nutrition.h Nutrition.cpp

## Targets to compile for each command
MAIN_TARGETS = main.cpp $(COOKBOOK_OUT) $(RECIPE_OUT) $(INGREDIENT_OUT) $(FRACTION_OUT) $(NUTRITION_OUT)
COOKBOOK_TARGETS = Cookbook.cpp
RECIPE_TARGETS = Recipe.cpp
INGREDIENT_TARGETS = Ingredient.cpp
FRACTION_TARGETS = Fraction.cpp
NUTRITION_TARGETS = Nutrition.cpp

all: main

## Main
main: $(MAIN_REQS)
	$(CC) $(MAIN_TARGETS) -o $(MAIN_OUT)

clean:
	rm *.o LazyChef cookbook.ini
