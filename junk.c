#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int contains_number(int container, int b);
int find_power(int number);

int main(){

 printf("%d",contains_number(163,63));
return 0;
}

int contains_number(int container, int b){
   /* Checks to see if container has b anywhere in it.
   */
   //First, figure out the power of b to figure out how to do it.
    int x;
    //finds number of digits to compare.
    x = pow(10,find_power(b));
    printf("x= %d\n",x);
    while(container > 0){
        //if b is contained.
        if((container % x) == b) return 1;
        //moves on to next check.
        container = container/(10);
    }

    return 0;
}

int find_power(int number){
/*
    if(number < 10)
        return 10;
    else if (number < 100){
        return 100;
    } else if (number < 1000)
        return 1000;
    else if (number < 10000)
        return 10000;
    else if(number < 100000)
        return 100000;
    else if (number < 1000000)
        return 1000000;
    else return 10000000; */
        int n=0;
    while(1){
        if(number < pow(10,n)){
            break;
        }
        n++;
    }
    return n;
}
