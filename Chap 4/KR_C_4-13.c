/* Exercise 4-13. Write a recursive version of the function reverse(s), 
which reverses the string s in place */

#include<string.h>
#include<stdio.h>
void swap(char s[], int a, int b){
    char temp;
    temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}
void reverser(char s[], int i, int j) 
{
    int a = j - i;
    if (i < a)
    {
        swap(s, i, a);
        reverser(s, i + 1, j);
    }
}
int main(){
    char s[100] = "ABCDEF";
    reverser(s, 0, strlen(s) - 1);
    printf("%s", s);
}
 /* Confuse (need to be solved) : when I pass char *s, error "Exception has occurred.
Segmentation fault", but when I pass char s[], it run! @@ */
// -->solved: https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/ 