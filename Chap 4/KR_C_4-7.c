/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch? */
#include<stdio.h>
#include<string.h>
#include "polish_notation_getch.c"
void ungets(char *s){
    int i = 0;
    while (s[i] != '\0')
    {
        ungetch(s[i++]);
    }
}
main(){
    int c;
    char s[100] = "HELLO WORLD!";
    ungets(s);
    while ((c = getch()) >= 0)
    {
        printf("%c", c);
    }
}
/* ungets doesn't need to know about buf and bufp, but ungetch handle these
and error checking */