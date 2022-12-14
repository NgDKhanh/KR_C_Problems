/* Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s. */

#include<stdio.h>
#include<string.h>

void strcat(char s[], char t[])
{
    while(*s)
        s++;
    while (*s++ = *t++);
    
}
main(){
    char s[] = "HELLO ";
    char t[] = "WORLD!";
    strcat(s, t);
    printf("%s", s);
}