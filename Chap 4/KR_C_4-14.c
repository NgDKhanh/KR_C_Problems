/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges 
two arguments of type t. (Block structure will help.) */

#include<stdio.h>
#define swap(t, x, y) { t _z;   \
                        _z = x; \
                        x = y;  \
                        y = _z; }

main(){
    int a = 10, b = 5;
    swap(int, a, b);
    printf("a = %d, b = %d", a, b);
}