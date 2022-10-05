/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B. */
#include<stdio.h>
void strncpy(char s[], char t[], int n)
{
    int i = 0;
    while((*s++ = *t++) && (i++ < n));
    *s = '\0';
}
main(){
    char a[] = "Nguyen Doan Khanh";
    char b[12];
    strncpy(b, a, 18);
    printf("%s ", b);
}