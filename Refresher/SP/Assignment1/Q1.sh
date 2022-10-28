#!/bin/bash

# get the current hour through date command
hr=$(date "+%H")
min=$(date "+%M")	

# morning hours midnight to mid afternoon
if [ $hr -ge 0 -a $hr -lt 12 ]
then 
   msg="Good Morning, the time is $hr $min AM"
   
# afternoon hours mid afternoon to 6pm
elif [ $hr -ge 12 -a $hr -lt 18 ]
then
   msg="Good Afternoon, the time is $hr $min PM"
   
# evening hours 6pm to midnight

elif [ $hr -ge 18 -a $hr -lt 0 ]
then
   msg="Good Evening, the time is $hr $min PM"
fi

#GREET
echo $msg   
      
                   
