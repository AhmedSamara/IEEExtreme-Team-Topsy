#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int nek_length;
int longest_nek_length = 0;
int * nekops(int*, int);
void print_array(int*);
int K;

int main() {
    //scan in calue of k.
    scanf("%d", &K);
    //Prepare array of length of each nek_sequence.
    int nekop_length[K];

    int i=0;

    //can be any number 0 -> 255.
    //Just do 255 to be safe.
    int input[255];
    int buffer;
    int a;
    int input_length=0;

    while(a= scanf("%d ", &buffer)){
        //Stop when you can't read anymore.
        if(a != 1) break;
        input[input_length++] = buffer;
        //increment length of first nekop.
    }



    int output[K][999];

    nekop_length[0] = input_length;
    output[0][0] = nekops(input,nekop_length[0]);

    for(a=1; a <K; a++){
        nekop_length[a] = nek_length;
        output[a][0] = nekops(output[a-1][0], nekop_length[a]);
    }




    return 0;
}

void print_array(int * arr){
    int i;
    for(i=0; i < nek_length; i++){
        printf("%d ", arr[i]);
    }
}




int * nekops(int *input, int length){
    int nek_sequence[999];
    int n_index = 0;
    int i;
    int current_number;
    current_number = input[0];
    int n_count =0;
    for(i=0; i < length; i++){
        if(input[i] == current_number){
            //Keeps updating the count until it finds a new value.
            n_count++;
        } else{
            //Once new value is found.
            //Store count, current, number.
            nek_sequence[n_index++] = n_count;
            nek_sequence[n_index++]= current_number;

            //Reset values.
            current_number = input[i];
            n_count = 1;
        }

    }
    //It may exit without ever adding the last thing, so do this.

    if (nek_sequence[length-1] != current_number){
        nek_sequence[i++] = n_count;
        nek_sequence[i++] = current_number;
    }
    nek_length = i;

    return nek_sequence;
}
