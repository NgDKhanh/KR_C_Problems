#include<stdio.h>
#define ALLOCMAX 1000
char allocarray[ALLOCMAX];
char *allocp = allocarray;
char *alloc(int n){
	if(allocarray + ALLOCMAX - allocp >= n){
		allocp += n;
		return allocp - n;
	}
	else 
		return NULL;
}
