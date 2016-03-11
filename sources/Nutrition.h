#ifndef _NUTRITION_H_
#define _NUTRITION_H_

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

const string BASIC[]    = { "Energy", 
                            "Total lipid (fat)", 
                            "Fatty acid, total saturated",
                            "Fatty acids, total trans", 
                            "Fatty acids, total monounsaturated", 
                            "Fatty acids, total polyunsaturated", 
                            "Cholesterol", 
                            "Sodium, Na", 
                            "Carbohydrate, by difference", 
                            "Fiber, total dietary", 
                            "Sugars, total", 
                            "Protein" };
const string DETAILED[] = { "Calcium, Ca",
                            "Iron, Fe",
                            "Potassium, K", 
                            "Vitamin A, IU",
                            "Vitamin B-6",
                            "Vitamin B-12",
                            "Vitamin C, total ascorbic acid",
                            "Vitamin D" };
//const string FULL[]     = { "

class Nutrition
{
    private:
        string servingSize;
        map<string, map<string, float> > data;
    public:
        Nutrition();
	Nutrition(unsigned int n);
        void printBasic(string s);
        void printDetailed();
        void printFull();
        string getUnitsOfNutrient(string s);
        float getValueOfNutrient(string s);
};

#endif

/*
float Ash;
float Caffeine;
		float Calcium;
	float Calories;
	float Carbohydrate;
	float Cholesterol;
float Copper;
	float MonounsaturatedFat;
	float PolyunsaturatedFat;
	float SaturatedFat;
	float TransFat;
	float Fiber;
float Fluoride;
float Folate;
float FolicAcid;
float Glucose;
		float Iron;
float Magnesium;
float Niacin;
float Phosphorus;
		float Potassium;
	float Protein;
	float Sodium;
float Sucrose;
	float Sugars;
float Thiamin;
	float TotalFat;
		float VitaminA;
		float VitaminB12;
		float VitaminB6;
		float VitaminC;
		float VitaminD;
float VitaminE;
float VitaminK;
float Water;
float Zinc;
*/
