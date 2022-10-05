#include<stdio.h>
int htoi(char s[]){
    int j, integer = 0, pow = 1;
    for(j = 0; s[j] != '\0'; j++); // count digits of s
    j--;                           // j back to last subscript of s
    while(j >= 0 && s[j] != 'x' && s[j] != 'X'){
        if (s[j] >= '0' && s[j] <= '9')
            integer += (s[j] - '0')*pow;
        else if (s[j] >= 'a' && s[j] <= 'f')
            integer += (s[j] - 'a' + 10)*pow;
        else if (s[j] >= 'A' && s[j] >= 'F')
            integer += (s[j] - 'A' + 10)*pow;
        j--; pow *= 16;
    }
    return integer;
}
void getline(char s[]){
    int c, i = 0;
    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
}
main(){
    char s[100];
    getline(s);
    printf("Number that you've imported is: %d", htoi(s));
}