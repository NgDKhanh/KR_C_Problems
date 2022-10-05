/* Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value. */

#include<stdio.h>
#include<math.h>        /* for sin, exp, and pow */
#include<stdlib.h>      /* for atof() */
#include<string.h>
#include "polish_notation_calc.h"
#include "polish_notation_calc_main.h"
#define MAXOP 100       /* max size of operand or opererator */
      /* size that number was found */

/* reverse Polish calculator */
main()
{
    int type, var = 0;
    double v = 0.0;
    double op2;
    char s[MAXOP];
    int variable[26];
    for (int i = 0; i < 26; i++)
    {
        variable[i] = 0.0;
    }
    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case MATH:
            if(strcmp("sin", s) == 0)
                push(sin(pop()));
            else if(strcmp("exp", s) == 0)
                push(exp(pop()));
            else if(strcmp("pow", s) == 0)
                push(pow(pop(), pop()));
            break;
        case '=':
            pop();
            if(var >= 'A' && var <= 'Z'){
                variable[var - 'A'] = pop();
                push(variable[var - 'A']);
            }
            else printf("error assignment!");
            break;
        case '\n':
            v = pop();
            push(v);
            printf("%f\n", v);
            break;
        default:
            if(type >= 'A' && type <= 'Z'){
                push(variable[type - 'A']);
            }
            else if(type == 'v'){
                push(v);
            }
            else 
                printf("error: unknown command %s\n", s);
            break;
        }
        var = type; 
        //printf("var: %d\n", var);   
    }
    //printf("\nvar = %d\n", var); 
    
    return 0;
}