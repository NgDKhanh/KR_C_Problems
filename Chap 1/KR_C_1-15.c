#include<stdio.h>
#define MAX 300
float fahr_to_cel(float);
main(){
    for (float i = 0.0; i <= MAX; i += 20.0)
    {
        printf("cel: %6.3f\tfahr: %6.3f\n", fahr_to_cel(i), i);
    }
}
float fahr_to_cel(float i){
    return 5*(i - 32)/9;
}
