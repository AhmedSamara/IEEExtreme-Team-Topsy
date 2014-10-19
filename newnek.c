#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int nek_length;
void nekops(int*, int);
void print_array(int*, int);
int K;
int nek_field[999][999];
int current_row = 0;

int main(){

    //obtain value for K.
    scanf("%d",&K);

    //this will keep track of how long each Nekop is.
    int nek_lengths[K];

    /*
        We have an arbitrarily large 2D array, that we will fill as needed.
        we know that it will have K rows regardless, but the columns will vary.
        That's what this array is for, it keeps track of how many columns each row has.
    */

    //read in the original input.
    int a;
    int buffer;
    int input[999];
    int input_length;
 /*   while(a = scanf("%d ", &buffer)){
        //Stop when you can't read anymore.
        if(a != 1) break;
        input[input_length++] = buffer;
        //increment length of first nekop.
    }*/

    // {1,2,1,1};
    input[0] = 1;
    input[1] = 2;
    input[2] = 1;
    input[3] = 1;
    input_length = 4;


    //the first row and input_length columns of nek_field populated.
    nekops(input,input_length);
    print_array(input,input_length);
    //length of the produced pattern.
    nek_lengths[0] = nek_length;



    for(current_row=1; current_row < K; current_row++){
        //Create an input array from each previous nek_field row.
        int c;
        int temp_length = nek_lengths[current_row-1];
        int temp_input[temp_length];
        for(c=0; c <= nek_lengths[current_row-1]; c++){
            //using the nek results of the previous row as input.
            temp_input[c] = nek_field[current_row-1][c];
        }

        //now populate the row of nek_field and nek_lengths.
        nekops(temp_input, nek_lengths[current_row-1]);
        nek_lengths[current_row] = nek_length;
    }

    //Now print the nek_field.
    int rows;
    int columns;
    for(rows=0; rows<K; rows++){
        for(columns=0; columns < nek_lengths[rows]; columns++){
            printf("%d ", nek_field[rows][columns]);
        }
        printf("\n");
    }



    return 0;
}


void print_array(int * arr, int arr_length){
    int i;
    for(i=0; i < arr_length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void nekops(int *input, int length){
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
            nek_field[current_row][n_index++] = n_count;
            nek_field[current_row][n_index++]= current_number;

            //Reset values.
            current_number = input[i];
            n_count = 1;
        }

    }
    //It may exit without ever adding the last thing, so do this.

    if (nek_field[current_row][length-1] != current_number){
        nek_field[current_row][i++] = n_count;
        nek_field[current_row][i++] = current_number;
    }
    //main function will grab nek_length into array.
    nek_length = i;
}
