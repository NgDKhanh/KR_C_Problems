#include<stdio.h>
#define max 200
#define in 1   //in a line
#define out 0  //out a line
main(){
    int c;
    int len = 0; int subs = 0;
    int state = out;
    int a[max];   // array of lines
    char s[max][max];  // array of characters in a line
    while ((c = getchar()) != EOF)
    {
        len++;
        if(c == '\n'){
            if(state == in){
                state = out;
                a[subs] = len;
                subs++; len = 0;
            }
        } else
        {
            if (state == out) {
                len = 0;
                state = in;
            }
            s[subs][len] = c;
        }
    }
    for (int i = 0; i < subs; i++)
    {
        if(a[i] >= 80){
        for(int t = 0; t < a[i]; t++){
            putchar(s[i][t]);
        }
        printf(":\t%d\n", a[i]);
    }
    }
}