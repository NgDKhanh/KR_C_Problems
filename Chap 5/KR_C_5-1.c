#include<stdio.h>
#include<ctype.h>
#include "getch.c"

int getint(int *pn){
    int c, sign;
    while(isspace(c = getch()));
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    int s;
    if(c == '+' || c == '-')
    {
        s = c;
        c = getch();
        if(!isdigit(c)) 
        {
            if(c != EOF)
                ungetch(c);
            ungetch(s);
            return s;
        }    
    }    
    for(*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}
main(){
    int n;
    int array[100];
    for(n = 0; n < 100 && getint(&array[n]) != EOF; n++);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    
}