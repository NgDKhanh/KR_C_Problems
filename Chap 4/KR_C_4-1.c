#include<stdio.h>
void getline(char s[]);
int strindex(char s[], char t);
main(){
    char s[100], t;
    printf("GETLINE: ");
    getline(s);
    printf("GET T: ");
    scanf("%c", &t);
    printf("Rightmost position of t in srting s: %d", strindex(s, t));
}
void getline(char s[]){
    int c, i = 0;
    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
}
int strindex(char s[], char t){
    int i, j = 0;
    while (s[j++] != '\0');
    j -= 2;
    for (i = j; i >= 0; i--)
    {
        if(s[i] == t) 
            return i;
    }
    return -1;
}