#include<stdio.h>
#define MAXLINE 300
int getline(char s[], int maxline);  //import a line of text
void reverse(char s[]);             // reverse imported line
main(){
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}
int getline(char s[], int maxline){
    int c, i, j;
    j = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if(i < maxline - 2){
            s[j] = c;
            j++;
        }
    }
    if(c == '\n'){
        s[j] = c;
        i++; j++;
    }
    s[j] = '\0';
    return i;
}
void reverse(char s[]){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    i--;
    if(s[i] == '\n') i--;
    int j = 0;
    char temp;
    while (j < i)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i--; j++;
    }    
}
