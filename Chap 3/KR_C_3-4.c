/* It's just example in K&R book. The solution of problem 3.4 is in C answer book.pdf */ 
#include<stdio.h>
void itoa(int n, char s[]);
void reverse(char s[]);
main(){
    int n;
    char s[100];
    printf("Import a number: ");
    scanf("%d", &n);
    itoa(n, s);
    printf("The numer that you've imported is: %s", s);
}
void reverse(char s[]){
    int i = 0, j = 0;
    while (s[j++] != '\0');
    j -= 2;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}
void itoa(int n, char s[]){
    int i = 0, sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
