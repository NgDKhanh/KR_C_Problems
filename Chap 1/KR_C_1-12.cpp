/* Exercise 1-12. Write a program that prints its input one word per line. */
#include <stdio.h>
#define in 1 /* inside a word */
#define out 0 /* outside a word */
main(){
    int state = out;
    int c;
    //int countw = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t'){
            if (state == in) printf("\n");
            state = out;
        } /* if encounter a ' ' or '\n' or '\t', that means we're outside a word */
        else if(state == out){
            state = in;
        } /* if encounter not a ' ' or '\n' or '\t', that means we're inside a word */
    if(state == in) putchar(c);
    }  
    //printf("%d", countw);
    
}