#include<stdio.h>
#define in 1  /* inside word */
#define out 0 /* outside word */
main(){
    int c;
    int count = 0; int countw = 0; int len = 0;
    int a[1000];
    char s[1000][1000];
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
                len = 0;
            }
        } 
        else {
            s[subs][len] = c; len++;
            if (state == out)
        {
            state = in;
            count = 0;
        }     
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for(int t = 0; t < 7; t++){
            putchar(s[i][t]);
        }
        printf(":\t%d \n", a[i]);
    }
}