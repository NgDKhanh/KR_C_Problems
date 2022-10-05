#include<stdio.h>
#include<stdlib.h>      /* for atof() */
#include<ctype.h>
#include "polish_notation_calc.h"
#include "polish_notation_calc_main.h"
#include "KR_C_4-10_getline.c"
#define MAXOP 100       /* max size of operand or opererator */
      /* size that number was found */

/* reverse Polish calculator */
main()
{
    int i, j;
    double op2;
    char s[MAXOP];
    char num[MAXOP];
 
    while ((getline(s)) > 0)
    {
        i = 0;
        while (s[i] != '\0')
        {
            j = 0;
            if (isdigit(s[i]))
            {
                while (isdigit(s[i]))
                {
                    num[j++] = s[i++];
                }
                num[j] = '\0';
                push(atof(num));
            }
            if (isspace(s[i])){
                while (isspace(s[i]))
                    i++;
            }
            if (s[i] == '+')
            {
                push(pop() + pop());
                i++;
            }
            if (s[i] == '-')
            {
                push(pop() - pop());
                i++;
            }
            if (s[i] == '*')
            {
                push(pop() * pop());
                i++;
            }
            if (s[i] == '/')
            {
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero division\n");
                i++;
            }
            if (s[i] == '\n'){
                printf("res %f\n", pop());
                i++;
            }
        }
        //printf("pop: %f", pop());
    }   
    return 0;
}