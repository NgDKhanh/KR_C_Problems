#include<stdio.h>
#define MAX 100
#define same 1 // a character in s1 matches with a character in s2
#define diff 0 // converse
void squeze(char s1[], char s2[]);
void getline(char s[]);
main(){
    char s1[MAX], s2[MAX];
    printf("import s1: ");
    getline(s1);
    printf("import s2: ");
    getline(s2);
    squeze(s1, s2);
    printf("%s", s1);
}
void getline(char s[]){
    int i = 0, c;
    while((c = getchar()) != '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0'; // end of text
}
void squeze(char a[], char b[]){
    int i, j, state;
    j = 0;
    for (i = 0; a[i] != '\0'; i++){
        state = diff;  // first set state = diff, then we test state
        for (int t = 0; b[t] != '\0'; t++)
        {
            if(a[i] == b[t]) state = same;   // test state
        }
        if (state == diff) a[j++] = a[i];  // if diff then add that character to new array
    }
    a[j] = '\0';
}
