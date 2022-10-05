#include<stdio.h>
int binsearch(int a[], int n, int v){
    int head = 0;
    int tail = n-1;
    int mid;
    while (head < tail - 1)
    {   
        mid = (head + tail)/2;
        if (v < a[mid]) tail = mid;
        else head = mid;
    }  
    if(a[mid] == v) return mid;
    else return -1;
}
main(){
    int n, v;
    printf("Import number of elements in array a: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    printf("Import number that you want to search: ");
    scanf("%d", &v);    
    printf("position of number that you're searching in array: %d", binsearch(a, n, v));
}
/* The difference in run-time is minimal. We did not gain much in performance and lost 
some in code readability. The original code on page 58 K&Rreads better from top to bottom. */