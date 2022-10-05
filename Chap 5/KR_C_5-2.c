/* Exercise 5-2. Write getfloat, the floating-point analog of getint. 
What type does getfloat return as its function value? */

#include<stdio.h>
#include<ctype.h>
#include "getch.c"

int getfloat(float *pn){
    int c;
    float sign, pow = 1.0;
    while(isspace(c = getch()));
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1.0 : 1.0;
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
    if(c == '.')
        c = getch();
    for(; isdigit(c); c = getch())
    {
        *pn = *pn * 10 + (c - '0');
        pow *= 10;
    }    
    *pn *= sign;
    *pn /= pow;
    if(c != EOF)
        ungetch(c);
    return c;
}
main(){
    int n;
    float array[100];
    for(n = 0; n < 100 && getfloat(&array[n]) != EOF; n++);
    for (int i = 0; i < 5; i++)
    {
        printf("%f ", array[i]);
    }     
}

/* The function returns either EOf or the ASCII value of the first character
after the floating-point number. The function type is int. */