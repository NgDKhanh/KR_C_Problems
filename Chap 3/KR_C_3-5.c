#include<stdio.h>
void itob(int n, char s[], int b);
void reverse(char s[]);
int abs(int n){
    return (n < 0) ? -n : n;
}
main(){
    int n, b;
    char s[100];
    printf("Import a number: "); scanf("%d", &n);
    printf("Import base: "); scanf("%d", &b);
    itob(n, s, b);
    printf("The number that you've imported in %d base: %s", b, s);
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
void itob(int n, char s[], int b){
    int i = 0;
    int sign = n;
    do
    {
        if(abs(n % b) >= 10) s[i++] = abs(n % b) -10 + 'A';
        else s[i++] = abs(n % b) + '0';
    } while (((n /= b)) != 0);
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
