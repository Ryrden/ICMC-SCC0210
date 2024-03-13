#!/bin/bash

# Clean all *.in and *.out files recursively in all folders

find . -name "*.in" -type f -delete
find . -name "*.out" -type f -delete
echo "All *.in and *.out files are deleted"
echo "Deleting README.txt"
find . -name "README.txt" -type f -delete
echo "README.txt is deleted"
echo "Deleting main binary"
find . -name "main" -type f -delete
echo "main binary is deleted"