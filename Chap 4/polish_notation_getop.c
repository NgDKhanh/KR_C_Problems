#include <ctype.h>
#include<stdio.h>
#include "polish_notation_calc.h"
 
/* getop: get next character or numeric operand */
int getop(char s[]) /* we pass s[] to getop to store input */
{
    int i, c;
 
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    //if (c != EOF)
        ungetch(c);
    return NUMBER;
}
 