#include<stdio.h>
#include<ctype.h>
double atof(char s[]);
void getline(char s[]);
main(){
    char s[100];
    getline(s);
    printf("Number: %f", atof(s));
}
void getline(char s[]){
    int c, i = 0;
    while ((c = getchar()) != '\n' && i < 100)
    {
        s[i++] = c;
    }
    s[i] = '\0';
}
double atof(char s[]){
    double power, sign;
    int i = 0, p = 0;
    double val = 0.0;
    if(s[i] == '-'){                               // test whether number is positive/negative
        sign = -1;
        i++;
    }
    for(; isdigit(s[i]) && s[i] != '\0'; i++){
        val = val*10 + (s[i] - '0');
    } 
    if(s[i] == '.') i++;
    for(power = 1.0; isdigit(s[i]) && s[i] != '\0'; i++){
        val = val*10 +(s[i] - '0');
        power *= 10;
    }
    if((s[i] == 'e' || s[i] == 'E') && s[++i] == '-') 
        i++;
    for(;isdigit(s[i]); i++)                      // take power of e (Eg. 123.45e-6)
        p = p*10 + (s[i] - '0');   
    while((p--) != 0)
        power = power*10;
    val /= power;
    val *= sign;
    return val;  
}
