#!/bin/bash

# This file will run tests on all the files in the current directory
# ending in .txt to verify if the sha512 value calculated using SHA512 
# file matches the correct sha512 value calculated using sha512sum.
echo -e "Running Tests..... \n"

for i in *.txt
do
    # Expected Output of the File using sha512sum. 
    expected="$(sha512sum $i)"
    # Output of the File using SHA512.
    output="$(./SHA512 $i)"
    # Converting output of output to lowercase.
    output=${output,,}
    # Adding file name to the end of output.
    joined=$output"  "$i 

    # Printing out to the screen.
    echo "Checking file $i. "
    echo "Output - $joined"
    echo "Expected - $expected"
    # Check if the outputs match
    if [[ "$joined" == "$expected" ]]; then
        echo -e "$i - Passed \n"
    else
        echo -e "$i - Failed \n"
    fi   
  
done
