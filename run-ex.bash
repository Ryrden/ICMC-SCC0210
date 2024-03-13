#!/bin/bash

code=$1
testcaseDir=$2
testcase=$3

# If no code, no testcaseDir or no testcase is provided, print usage
if [ -z "$code" ] || [ -z "$testcaseDir" ]; then
    echo "Usage: run-ex.bash <code>.<extension> <testcaseDir> [testcase]"
    echo "Example running inside the directory of the code:"
    echo "../run-ex.bash 03.py testcases"
    echo "or if you want to run a specific testcase:"
    echo "../run-ex.bash 03.cpp testcases 1"
    return
fi

lang=${code##*.}

echo "Running $code with testcases in $testcaseDir"

if [ $lang = "py" ]; then
    if [ -n "$testcase" ]; then
        echo "Running test case $testcase..."
        echo
        i=$testcaseDir/$testcase.in
        out=${i%.*}.out
        diff -y --suppress-common-lines <(python3 $code < $i) $out | expand -t 2
    else
        for i in $(ls $testcaseDir/*.in); do
            echo "Running test case $i..."
            echo
            out=${i%.*}.out
            diff -y --suppress-common-lines <(python3 $code < $i) $out | expand -t 2
        done
    fi
elif [ $lang = "cpp" ]; then
    # compile the code
    g++ $code -o main
    # if testcase is provided, run only that testcase
    if [ -n "$testcase" ]; then
        echo "Running test case $testcase..."
        echo
        i=$testcaseDir/$testcase.in
        out=${i%.*}.out
        diff -y <(./main < $i) $out | cat -n 
    else
        for i in $(ls $testcaseDir/*.in); do
            echo "Running test case $i..."
            echo
            out=${i%.*}.out
            diff -y --suppress-common-lines <(./main < $i) $out | cat -n
        done
    fi
    find . -name "main" -type f -delete
fi
