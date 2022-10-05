/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive routine. */

#include<stdio.h>
#include<ctype.h>
#include<math.h>

void printd(int n, char *s){
    static int i;           // i will retain its value after each recursion
    int k = n;              // k stores the value of n
    if(n < 0)
    {
        s[0] = '-';
        n = -n;
        i = 1;
    } 
    if(n / 10)
        printd(n / 10, s);
    s[i++] = (n % 10) + '0';
    if(n == abs(k))         // test if it's the last recursion then push end of text to string s
        s[i] = '\0';
}
main(){
    int n;
    char s[100];
    scanf("%d", &n);
    printd(n, s);
    printf("%s", s);
}