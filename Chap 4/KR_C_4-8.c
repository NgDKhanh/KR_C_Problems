/* Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly. */
#include<stdio.h>
#define BUFSIZE 100
 
int bufp = 0;
/* getch: the function which actually gets chars! */
int getch(void) /* get a (possibly pushed-back) character */
{
    int c;
    if (bufp != 0)
    {
        c = bufp;
        bufp = 0;
        return c;
    }
    else return getchar();
}
 
void ungetch(int c) /* push character back in input */
{
    if (bufp != 0)
        printf("ungetch: too many characters\n");
    else
        bufp = c;
}