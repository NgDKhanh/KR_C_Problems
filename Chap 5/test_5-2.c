#include <stdio.h>
/* echo command-line arguments; 2nd version */
main(int argc, char *argv[])
{
    printf("You have enterd %d arguments: \n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    
}