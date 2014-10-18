#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int length;
int nek_length;
int * nekops(int*);
void print_array(int*);

int main() {
    length = 4;
    int test[4] = {1, 2, 1, 1 };

    print_array(nekops(test));

    return 0;
}

void print_array(int * arr){
    int i;
    for(i=0; i < nek_length; i++){
        printf("%d ", arr[i]);
    }
}



int * nekops(int *input){
    //Pick arbitrarily large length.
    int nek_sequence[length*999];
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
