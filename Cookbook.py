#!/usr/bin/env python3

from Recipe import Recipe

class Cookbook:
    def __init__(self):
        self.entries = []
        _file = open("cb_contents.txt")
        for i in _file:
            self.add_recipe(Recipe(str("recipes/"+i).strip()))
        _file.close()

    def get_recipe(self, index):
        return self.entries[index]

    def add_recipe(self, recipe):
        self.entries.append(recipe)

    def length(self):
        return len(self.entries)

    def show(self):
        print("\n\n")
        for i in self.entries:
            print(str("Recipe "+str(i.id+":").ljust(5)+i.name))
        print("\n\n")
