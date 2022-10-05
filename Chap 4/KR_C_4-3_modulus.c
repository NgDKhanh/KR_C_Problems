/* Given the basic framework, 
it's straightforward to extend the calculator. */

#include<stdio.h>
#include<stdlib.h>      /* for atof() */
#include<math.h>
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
                printf("error: zero divison\n");
            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                push(fmod(pop(), op2));
            else    
                printf("error: zero modulus\n");
            break;
        case '\n' :
            printf("RESULT: %.8g\n", pop());
            break;          
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}