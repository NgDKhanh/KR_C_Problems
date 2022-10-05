#include<stdio.h>
#include<string.h>
#define MAXLINE 100
int getline(char s[], int max){
    int c;
    char *p = s;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p; 
}
main(){
    char s[MAXLINE];
    while (getline(s, MAXLINE) > 0)
        printf("%s", s);
}