#!/usr/bin/env python3

import xml.etree.ElementTree as ET

class Nutrients:
    def __init__(self):
        self.nutrient_list = []

    def load(self, file_path):
        xml = ET.parse(open(file_path)).getroot()
        for i in xml[2]:
            self.nutrient_list.append([i.attrib["name"],i.attrib["amount"],i.attrib["units"]])

    def show(self):
        for i in range(len(self.nutrient_list)):
            print(str(self.nutrient_list[i][0]).ljust(35)+str(self.nutrient_list[i][1]).rjust(10),str(self.nutrient_list[i][2]))
        print("\n\n")
