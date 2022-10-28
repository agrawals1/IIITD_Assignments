#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
int main()
{
    int id1 = fork();
    int id2 = fork();
    int id3 = 1234;
    int id4 = 5678;
    if(id1 !=0 && id2==0 || id1 ==0 && id2 !=0)
    {
        id3 = fork();
    }
    if(id1 == 0 && id2 != 0 && id3 == 0)
    {
        fork();
        
    }
    printf("END");
    return 0;
}