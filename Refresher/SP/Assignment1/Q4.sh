# checking number of arguments
if (( $# <= 0 || $# > 2 ))
then
    echo "1.Please enter atleast 1 argument and atmost 2 arguments"
    exit
# check if the first argument is actually a valid directory path through -d    
fi    
if [[ ! -d $1 ]]
then
    echo "2.Directory does not exist..."
    exit
fi
# check read permission thrugh -r
if [[ ! -r $1 ]]
then
    echo "3.Directory not readable..."    
    exit
fi
#   check if there is any extension provided as second argument. awk reads the input line by line and the number of lines read by #   awk can be accessed through NR
if [[ ! $2 ]]
then
    ls $1 | awk 'END{print NR}'
    exit    
fi    
#     using find to check for all the files with the given extension and counting using wc -l. -maxdepth option stops find from #     checking recursively in subdirectories. regex to match the file name can be provided through -name option
find $1 -maxdepth 1 -name "*$2" | wc -l


