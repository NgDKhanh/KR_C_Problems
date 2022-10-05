#include<stdio.h>
void expand(char s1[], char s2[]);
void getline(char s[]);
main(){
    char s1[100], s2[100];
    getline(s1);
    expand(s1, s2);
    printf("%s", s2);
}
void getline(char s[]){
    int c, i;
    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
}
void expand(char s1[], char s2[]){
    int i = 0, j = 0;
    char c;
    while ((c = s1[i++]) != '\0')
    {
        if(s1[i] == '-'){
            i++;
            while (c < s1[i])
            {
                s2[j++] = c++;
            }
            
        } else s2[j++] = c;
    }
    s2[j] = '\0';
}