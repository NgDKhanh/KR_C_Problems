#include <ctype.h>
#include<stdio.h>
#include "polish_notation_calc.h"
 
/* getop: get next character or numeric operand */
int getop(char s[]) /* we pass s[] to getop to store input */
{
    int i, c;
    static int lastc;
    if(lastc != 0 && lastc != ' '){
        int temp = lastc;
        lastc = 0;
        return temp;
    }
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    //if (c != EOF)
    lastc = c;
    return NUMBER;
}
 