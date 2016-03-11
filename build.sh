#!/bin/bash

# Building the program
echo "Building Program..."
cd sources
make clean 2>/dev/null
make
echo
 
if [ -e LazyChef ] ; then
	# Dynamically initialize the cookbook.ini
	echo "Creating Cookbook..."
	ls ./recipes/ > cookbook.ini
	echo "done!"
	echo 

	# Run the Program
	echo "Running LazyChef..."
	sleep 2
	./LazyChef
fi
