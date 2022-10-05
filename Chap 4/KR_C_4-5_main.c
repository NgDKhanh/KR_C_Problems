/* Exercise 4-5. Add access to library functions like sin, exp, and pow. */

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
    int type;
    double op2;
    char s[MAXOP];
 
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
        case '\n':
            printf("%.8g\n", pop());
            break;
        case MATH:
            if(strcmp("sin", s) == 0)
                push(sin(pop()));
            else if(strcmp("exp", s) == 0)
                push(exp(pop()));
            else if(strcmp("pow", s) == 0)
                push(pow(pop(), pop()));
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}