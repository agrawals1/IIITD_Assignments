#!/bin/bash
# check if the number is passed as command line argument. $# stores the no. of command line arguments
if [ $# -le 0 ]
then
    echo "please enter the number as a command line argument : ex- ./Q2.sh 123"
    exit
fi
    
lst_digit=0
rev_num=0
num=$1

#recursively extract the remainder of the number, dividing by 10 and use it to form the reverse number
while [ $num -ne 0 ]

do
    lst_digit=$(( $num%10 ))
    rev_num=$(( $rev_num*10 + $lst_digit ))
    num=$(( $num/10 ))
done
echo "reversed number is $rev_num"    
