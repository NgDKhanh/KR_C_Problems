//Write a program to print a histogram of the frequencies of different characters in its input
#include<stdio.h>
#define MAX 180
main(){
    int a[MAX];
    char s[MAX];
    for(int i = 0; i <= MAX; i++) a[i] = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            a[c]++;
        }
    }
    for(int i = 0; i < MAX; i++){
        if(a[i] != 0){
            printf("%c: %d\n", i, a[i]);
        }
    }
}