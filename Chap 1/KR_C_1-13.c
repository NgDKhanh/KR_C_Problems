#include<stdio.h>
#define in 1  /* inside word */
#define out 0 /* outside word */
main(){
    int c;
    int count = 0; int countw = 0;
    int a[1000];
    int subs = 0;
    int state = out;
    while ((c = getchar()) != EOF)
    {
        ++count;
        if(c == ' ' || c == '\n'){
            if(state == in){
                a[subs] = count;
                subs++;
                state = out;
            }
        } 
        else if (state == out)
        {
            state = in;
            count = 0;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        printf("word %d : %d \n", i, a[i]);
    }
}