#include<stdio.h>
#define MAX 100
//
int any(char s1[], char s2[]);
void getline(char s[]);
int main()
{
    char s1[MAX], s2[MAX];
    printf("import s1: "); getline(s1);
    printf("import s2: "); getline(s2);
    printf("%d", any(s1, s2));
    //printf("s1: %s\ns2: %s", s1, s2);
    return 0;
}
void getline(char s[]){
    int c, i = 0;
    while ((c = getchar()) != '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';   
}
int any(char s1[], char s2[]){
    int count = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        for(int j = 0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j]) count++;
            if (count == 1) return i+1;
        }
    }
    if(count == 0) return -1;
}