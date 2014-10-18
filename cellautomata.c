#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int N = 3;
void print_as_asterix(int* , int );

int main() {
    int rule;
    int max_iter;
    int initial;
    scanf("%d %d %d %d", &rule, &max_iter, &N, &initial);

    int binary_rep[N];
    //initialize binary rep to zero.
    //appropriate bits will be set to 1.
    printf("enter an initial value\n");
   // scanf("%d",&initial);
    int a = 1;
    int i;
    //convert value to binary array representation.
    for(i=0; i < N; i++){
        binary_rep[i] = (initial & a) && 1;

        a = a << 1;
    }
    print_as_asterix(binary_rep,N);

    //
    int new_binary[N];


    for (max_iter; max_iter >0; max_iter--){
        //create the next line.
        for(i=0; i < N; i++){
            new_binary[i] = new_value(binary_rep,i);
            //printf("%d",new_binary[i]);
        }
        print_as_asterix(new_binary,N);

        //Make the "new" line the previousline.
        for(i=0; i < N; i++){
            binary_rep[i] = new_binary[i];
        }
       // printf("\n");
    }



    return 0;
}
void print_as_asterix(int* arr, int length){
    int x;
    for(x=0; x<length;x++){
        if(arr[x]){
            printf("*");
        }else{
            printf(" ");
        }
    }
    printf("\n");
}

int new_value(int*rep, int index){
    int nm1, np1, n;
    //corner cases.
    if(index == 0){
        nm1 = 0;
    }else{
        nm1 = rep[index-1];
    }
    if(index == N-1){
        np1 = 0;
    } else{
        np1 = rep[index+1];
    }
    n = rep[index];

    int a,b,c;
    a= nm1;
    b= rep[index];
    c = np1;
    return (!a&&c)||(!a&&b)||(a&&!b&&!c);

    /*
    if(nm1 && n && np1){
        return 0;
    }
     else if (nm1 && n && !np1){
        return 0;
     }
     else if(nm1 && !n && )

    return */

}
