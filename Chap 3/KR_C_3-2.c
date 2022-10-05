#include<stdio.h>
#define MAX 100
void escape(char s[], char t[]);
void getline(char s[]);
main(){
    char s[100], t[100];
    printf("Import lines of text that include newline and tab character: ");
    getline(s);
    escape(s, t);
    printf("We convert character of newline and tab into visible characters '\\n' and '\\t': %s", t);;
}
void getline(char s[]){
    int c, i = 0;
    while ((c = getchar()) != EOF)
    {
        s[i++] = c;
    }
    s[i] = '\0';
}
void escape(char s[], char t[]){
    int i, j = 0;
    for(i = 0; s[i] != '\0'; i++){
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\'; 
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
        default:
            t[j++] = s[i];
            break;
        }
    }
    t[j] = '\0';
}
