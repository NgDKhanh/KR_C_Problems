/* Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach. */
#include<stdio.h>
int getline(char *s){
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}