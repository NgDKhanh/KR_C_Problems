#include<stdio.h>
#include<string.h>
main(){
    int c;
    //int cb = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
             while(c == ' ') c = getchar();
             printf(" ");
        }
        putchar(c);
}
}