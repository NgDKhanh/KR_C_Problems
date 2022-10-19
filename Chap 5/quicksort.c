#include<stdio.h>

void swap(int *v, int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void qsort(int *v, int left, int right)
{
	int last;
	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(int i = left + 1; i <= right; i++)
	{
		if(v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}	
int main(){
	int a[5] = {2, 5, 1, 5, 3};
	qsort(a, 0, 4);
	for(int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	return 0;
}	

