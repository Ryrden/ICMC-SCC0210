#!/bin/bash

# Colors for better output readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

code=$1
testcaseDir=$2
testcase=$3

# If no code, no testcaseDir, or no testcase is provided, print usage
if [ -z "$code" ] || [ -z "$testcaseDir" ]; then
    echo -e "${RED}Usage:${NC} run-ex.bash <code>.<extension> <testcaseDir> [testcase]"
    echo -e "${YELLOW}Example running inside the directory of the code:${NC}"
    echo -e "  ../run-ex.bash 03.py testcases"
    echo -e "${YELLOW}or if you want to run a specific testcase:${NC}"
    echo -e "  ../run-ex.bash 03.cpp testcases 1"
    return
fi

lang=${code##*.}
prefix=${code%.*}

# Check and unzip if necessary
if ! ls $testcaseDir/*.in 1> /dev/null 2>&1 || ! ls $testcaseDir/*.out 1> /dev/null 2>&1; then
    zipfile="$testcaseDir/$prefix.zip"
    if [ -f "$zipfile" ]; then
        echo -e "${BLUE}Extracting $zipfile...${NC}"
        unzip -o $zipfile -d $testcaseDir
        # Rename files with prefix
        for file in $testcaseDir/*; do
            # If ends with .in or .out
            if [[ $file == *.in || $file == *.out ]]; then
                mv "$file" "$testcaseDir/$prefix-$(basename $file)"
            fi
        done
    else
        echo -e "${RED}Error: Test case zip file not found.${NC}"
        exit 1
    fi
fi

echo -e "${BLUE}Running $code with test cases in $testcaseDir${NC}"

run_test() {
    local input_file=$1
    local output_file=${input_file%.*}.out

    echo -e "${YELLOW}Running test case $input_file...${NC}"
    echo

    if [ $lang = "py" ]; then
        diff_output=$(diff -y --suppress-common-lines <(python3 $code < $input_file) $output_file | expand -t 2)
    elif [ $lang = "cpp" ]; then
        diff_output=$(diff -y --suppress-common-lines <(./main < $input_file) $output_file | expand -t 2)
    fi

    if [ -z "$diff_output" ]; then
        echo -e "${GREEN}Test case $input_file passed.${NC}"
    else
        echo -e "${RED}Test case $input_file failed.${NC}"
        echo "$diff_output"
    fi
    echo
}

if [ $lang = "py" ]; then
    if [ -n "$testcase" ]; then
        run_test $testcaseDir/$prefix-$testcase.in
    else
        for input_file in $(ls $testcaseDir/$prefix-*.in); do
            run_test $input_file
        done
    fi
elif [ $lang = "cpp" ]; then
    # Compile the code
    echo -e "${BLUE}Compiling $code...${NC}"
    g++ $code -o main
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed.${NC}"
        exit 1
    fi

    # Run test cases
    if [ -n "$testcase" ]; then
        run_test $testcaseDir/$prefix-$testcase.in
    else
        for input_file in $(ls $testcaseDir/$prefix-*.in); do
            run_test $input_file
        done
    fi

    # Clean up
    find . -name "main" -type f -delete
fi

# Clean up extracted test cases
echo -e "${BLUE}Cleaning up extracted test cases...${NC}"
rm $testcaseDir/$prefix-*.in $testcaseDir/$prefix-*.out $testcaseDir/README.txt
if [ $lang = "cpp" ]; then
    rm $testcaseDir/main
fi
echo -e "${GREEN}All done.${NC}"
