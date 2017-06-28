#!/usr/bin/env python3

import sys
import xml.etree.ElementTree as ET

from Cookbook import Cookbook

def close():
    sys.exit()

def menu():
    print("Menu\n"+
          "1: Show CookBook\n"+
          "2: Show Recipe\n"+
          "3: Quit")
    opt=0
    while opt > 3 or opt < 1:
        opt=input("Which menu option: ")
        opt=int(opt)
    if opt == 1:
        cookbook.show()
    elif opt == 2:
        opt=0
        while opt > cookbook.length() or opt < 1:
            opt=input("Which recipe: ")
            opt=int(opt)
        cookbook.get_recipe(opt - 1).show()
    elif opt == 3:
        close() 
    else:
        return

def main():
    while True:
        menu()

if __name__ == "__main__":
    cookbook = Cookbook()
    main()
