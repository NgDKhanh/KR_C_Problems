/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise */

#include<stdio.h>
#include<string.h>

int strend(char s[], char t[])
{
    int icl;
    while (*s)
        s++;
    s--;
    while (*t)
        t++;
    t--;
    for (icl = 0; *t > 0 && *s > 0; s--, t--)
    {
        if(*s != *t)
            return icl;
    }
    icl = 1;
    return icl;
    
}
main(){
    char s[] = "HELLO WORLD!";
    char t[] = "LD!";
    printf("%d", strend(s, t));
}