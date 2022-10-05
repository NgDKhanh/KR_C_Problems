#include<stdio.h>
#include<stdlib.h>
#define NUMBER '0'
void push(double n);
double pop();
int getop(char []);
main(){
    int type;
    char s[100];
    double op2;
    while((type = getop(s)) != EOF){
        switch (type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(pop() - pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else printf("ARITHMETICALLY ERROR!");
            break;
        case '\n':
            printf("RESULT: %f\n", pop());   
            break; 
        default:
            printf("SYNTAX ERROR!");
            break;
        }
    }
}
int cp = 0;
double stack[100];
void push(double n){
    if(cp > 100)
        printf("FULL STACK");
    else{
        stack[cp++] = n;
    }
}
double pop(){
    if(cp < 0) return 0;
    else return stack[--cp];
}
#include<ctype.h>
int getch(void);
void ungetch(int);
int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ');
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    //if(isdigit(c))  // get number
        while(isdigit(s[++i] = c = getch()));
    if(c == '.') 
        while(isdigit(s[++i] = c = getch())); //
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
int buf[100];
int bufp = 0;
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
    if(bufp < 100) buf[bufp++] = c;
    else printf("ERROR UNGETCH!");
}
