#include<stdio.h>
#define MAXLINE 300
int getline(char s[], int maxline);
main(){
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0) // if there was a line
    {
        printf("%s", line);
    }
}
int getline(char s[], int maxline){
    int c, i;
    i = 0;
    int okloop = 1;  // state of a loop. if ok with condition->continue the loop, else stop
    while(okloop == 1){
        if(i >= maxline - 1) okloop = 0;
        else if ((c = getchar()) == '\n') okloop = 0;
        else if(c == EOF) okloop = 0;
        else {
            s[i] = c;
            i++;
        }
    }
    if (i > 0)  // test if there was atleast a character
    {
        s[i] = '\n'; 
        i++;
    }
    s[i] = '\0'; // end pf a text
    return i;
}