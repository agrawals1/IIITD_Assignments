#!/bin/bash
echo "enter a,b,c,d"
# read the values in an array through -a
read -a vars
# evaluate the expression
echo "The value of ${vars[0]}*20 - ${vars[1]}*2 + ${vars[2]}/${vars[3]} is $(( ${vars[0]}*20 - ${vars[1]}*2 + ${vars[2]}/${vars[3]} ))"
