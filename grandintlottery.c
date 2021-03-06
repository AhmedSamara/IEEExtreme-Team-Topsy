#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N;
int sequence_length;
int find_power(int );
int contains_number(int , int );

int main() {
    int min_val;
    int max_val;
    int winner_i;

    scanf("%d %d %d %d",&min_val,&max_val
                    ,&winner_i,&N);
    int seq_length = max_val - min_val;

    if(winner_i < 1 || winner_i > 1000000 || N > 18
       )
       {
        printf("DOES NOT EXIST\n");
        return 0;
    }

    int picks[N];
    int a;
    //scan in picks.
    for(a=0; a < N; a++){
        scanf("%d", &picks[a]);
    }


    int contain_count = 0;

    //default to max possible length.
    int lotto_sequence[99999];
    int i;

    for(a= min_val; a<=max_val; a++){
        //iterates through all numbers that may be added to lotto_sequence.
        for(i=0;i<N;i++){
         //   if(a < picks[i]) continue;
         if (!already_in_there(a,lotto_sequence,contain_count)){
            if (contains_number(a,picks[i])){
                //store val, keep track of size.


                    lotto_sequence[contain_count++] = a;
                    if (contain_count >= winner_i-1) break;
                }
                //printf("%d\n",a);
            }
        }
        if (contain_count >= winner_i) break;
    }

    if ((winner_i-1 >= contain_count))
        printf("DOES NOT EXIST\n");
    else{
        printf("%d",lotto_sequence[winner_i-1]);
    }


    return 0;
}


int contains_number(int container, int b){
   /* Checks to see if container has b anywhere in it.
   */
   //First, figure out the power of b to figure out how to do it.
    int x;
    //finds number of digits to compare.

    x = find_power(b);
    while(container >= b){
        //if b is contained.
        if((container % x) == b) return 1;
        //moves on to next check.
        container = container/(10);
    }

    return 0;
}
int already_in_there(int number, int arr[], int length);
int already_in_there(int number, int arr[], int length){
    int i=0;
    for(i=length-1; i >=0; i--){
        if (arr[i] == number)
            return 1;
    }
    return 0;
}

int find_power(int number){
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
    else return 10000000;
    /*int n=0;
    int d;
    while(1){
        d = pow(10,n);
        if(number < d){
            break;
        }
        n++;
    }
    return d; */
}
