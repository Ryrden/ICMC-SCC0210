#!/bin/bash

code=$1
dir=$2
lang=$3

if [ $lang = "py" ]; then
    for i in $(ls $dir/*.in); do
        out=${i%.*}.out
        diff -c -b <(python3 $code < $i) $out
    done
elif [ $lang = "cpp" ]; then
    # compile the code
    g++ $code -o main
    for i in $(ls $dir/*.in); do
        out=${i%.*}.out
        diff -c -b <(./main < $i) $out
    done
fi
