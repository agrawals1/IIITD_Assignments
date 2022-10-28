#!/bin/bash
my_array=( $(<find $1 -maxdepth 1 -name "*.c">) )
#find $1 -maxdepth 1 -name "*.c" | var
for my_file in $my_array
do
    name=$(echo "$my_file" | cut -f 1 -d '.')
    make name

done