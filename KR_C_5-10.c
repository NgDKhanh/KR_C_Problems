#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define NUM (isdigit(x) ? 't' : 'f')
#define MAXSTACK 100
int stack[MAXSTACK];
int sp = 0;
void push(int n){
	if(sp >= MAXSTACK)
		printf("Full stack\n");
	else
		stack[sp++] = n;
}
int pop(void){
	if(sp < 0)
		printf("Empty stack\n");
	else 
		return stack[--sp];
}
int main(int argc, char *argv[]){
	int i = 1;
	char num;
	while(i < argc){
		num = argv[i][0];
		switch(num){
			case 't':
				push(atoi(argv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(pop() - pop());
				break;
			default:
				printf("ERROR\n");
		}
		i++;
	}
	printf("%d\n", pop());
	return 0;
}


