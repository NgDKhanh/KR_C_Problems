#include<stdio.h>
void reverse(char s[]);
void itoa(int n, char s[], int w);
main(){
    int n, w;
    char s[100];
    scanf("%d%d", &n, &w);
    itoa(n, s, w);
    printf("%s", s);
}
void reverse(char s[]){
    int i = 0, j = 0;
    while (s[j++] != '\0');     // count 
    j -= 2;                     // bring j back to the last subscipt
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}
void itoa(int n, char s[], int w){
    int i = 0, sign;
    if((sign = n) < 0) n = -n;
    do
    {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);
    if(sign < 0) s[i++] = '-';
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}