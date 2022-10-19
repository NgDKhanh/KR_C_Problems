#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "alloc.c"
#include "getline.c"
#define MAXLINE 1000
#define MAXLEN 100
char *lineptr[MAXLINE];
int readlines(char *lineptr[], int maxline);
void writelines(char *lineptr[], int nline);
void qsortl(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *); 

int main(int argc, int *argv[]){
	int nline, numeric;
	numeric = 0;
	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if((nline = readlines(lineptr, MAXLINE)) >= 0){
		qsortl(lineptr, 0, nline - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nline);
		return 0;
	}
	else {
		printf("error readlines !\n");
		return 1;
	}
}
int readlines(char *lineptr[], int maxline){
	int nline, len;
	char *p;
	nline = 0;
	char line[MAXLEN];
	while((len = getlines(line, MAXLEN)) > 0){
		if(nline > maxline || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nline++] = p;
		}
	}
	return nline;
}
void writelines(char *lineptr[], int nline){
	for(int i = 0; i < nline; i++)
		printf("%s\n", lineptr[i]);
}
void swap(void *v[], int a, int b){
	void *temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void qsortl(void *v[], int left, int right, int (*comp)(void *, void *)){
	if(left >= right) 
		return;
	swap(v, left, (left + right)/2);
	int last = left;
	for(int i = left + 1; i <= right; i++){
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsortl(v, left, last - 1, comp);
	qsortl(v, last + 1, right, comp);
}
int numcmp(char *s1, char *s2){
	int i1 = atoi(s1);
	int i2 = atoi(s2);
	if(i1 > i2)
		return 1;
	if(i1 < i2) 
		return -1;
	if(i1 == i2)
		return 0;
}
