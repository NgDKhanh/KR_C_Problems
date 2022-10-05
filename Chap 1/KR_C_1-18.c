#include<stdio.h>
#define MAXLINE 300
int getline(char line[], int maxline);
int remove(char s[]);
main(){
    int c;
    char line[MAXLINE];
    while(getline(line, MAXLINE) > 0)
            if(remove(line) > 0)
               printf("%s", line);   
}
int getline(char s[], int maxline){
    char c;
    int j = 0;
    int i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if(i < maxline - 2){
            s[j] = c;
            j++;
        }
    }
    if (c == '\n')
    {
        s[j] = c;
        i++; j++;
    }
    s[j] = '\0';
    return i;
}
int remove(char s[]){
    int i = 0;
    while(s[i] != '\n') i++;
    i--;
    while (i >= 0 && (s[i] == ' '))
    {
        i--;
    }
    if (i >= 0)
    {
        i++;
        s[i] = '\n';
        i++;
        s[i] = '\0';
    }
    return i;
    
}