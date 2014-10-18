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

    int picks[N];
    int a;
    for(a=0; a < N; a++){
        scanf("%d\n", &picks[a]);
    }

    int lotto_sequence[9999];
    //numbers can't be 0, so will use this to mark end.
    int i;
    for(i=0; i<9999; i++){
        lotto_sequence[i]=0;
    }
    int lotto_index=0;
    //generate lotto sequence.
    int candidate_number;
    int j=0;
    for(candidate_number = min_val;
        candidate_number<= max_val;
         candidate_number++){
        //check if any of picks are contains.
        for(j=0;j<N;j++){
            if (
                contains_number(candidate_number,picks[j])
                ){
                    lotto_sequence[lotto_index++] = candidate_number;
                }
        }
    }



    printf("%d",lotto_sequence[winner_i]);

    return 0;
}


int contains_number(int container, int b){
   /* Checks to see if container has b anywhere in it.
   */
   //First, figure out the power of b to figure out how to do it.
    int x;
    //finds number of digits to compare.
    x = pow(10,find_power(b));
    while(container > 0){
        //if b is contained.
        if((container % x) == b) return 1;
        //moves on to next check.
        container = container/(10);
    }

    return 0;
}

int find_power(int number){
    int n = 0;
    while(1){
        if(number < pow(10,n)){
            break;
        }
        n++;
    }

    return n;
}
