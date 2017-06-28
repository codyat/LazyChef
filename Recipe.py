#!/usr/bin/env python3

import xml.etree.ElementTree as ET

from Nutrients import Nutrients

class Recipe:
    def __init__(self):
        self.id = 0
        self.name = ""
        self.prep_time = ""
        self.cook_time = ""
        
        self.ingredients = []
        self.steps = []
        self.nutrients = Nutrients()

    def __init__(self, file_path):
        xml = ET.parse(open(file_path)).getroot()

        self.id = xml.attrib["id"]
        self.name = xml.attrib["name"]
        self.prep_time = xml.attrib["prep_time"]
        self.cook_time = xml.attrib["cook_time"]

        self.ingredients = []
        self.steps = []
        self.nutrients = Nutrients()
        self.nutrients.load(file_path)

        for i in xml[0]:
            self.ingredients.append([i.attrib["name"], i.attrib["amount"], i.attrib["units"]])

        for i in xml[1]:
            self.steps.append(i.text)

    def show(self):
        print("Recipe #" + self.id + "\n")
        print("Name: " + self.name + "\nId:   " + self.id + "\nPrep: " + self.prep_time + "\nCook: " + self.cook_time + "\n")
        
        for i in range(len(self.ingredients)):
            print("  " + str(self.ingredients[i][0]).ljust(20) + str(self.ingredients[i][1]).rjust(5), self.ingredients[i][2])

        print()
        for i in range(len(self.steps)):
            print("  Step" , str(i + 1) + ": " + self.steps[i])

        print()
        self.nutrients.show()
