#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int N;
void print_as_asterix(int[] , int );
int new_value(int[], int );
int row =1;
int main() {
    int rule;
    int max_iter;
    int initial;

    scanf("%d %d %d %d", &rule, &max_iter, &N, &initial);

    int binary_rep[N];
    //initialize binary rep to zero.
    //appropriate bits will be set to 1.
   // scanf("%d",&initial);
    int a = 1;
    int i;
    //convert value to binary array representation.
    for(i=N-1; i >=0; i--){
        binary_rep[i] = (initial & a) && 1;

        a = a << 1;
    }
    print_as_asterix(binary_rep,N);

    //
    int new_binary[N];

    int j=0;
    for (j=0; j < max_iter-1; j++){
        int stable = 1;
        //create the next line.
        for(i=0; i < N; i++){
            new_binary[i] = new_value(binary_rep,i);
            //printf("%d",new_binary[i]);
            //assume that it's stable until proven otherwise.
            if(new_binary[i] != binary_rep[i])
                stable = 0;

        }
        if(stable) break;
        print_as_asterix(new_binary,N);
        //once it's stable, done.

        //Make the "new" line the previousline.
        for(i=0; i < N; i++){
            binary_rep[i] = new_binary[i];
        }
       // printf("\n");
    }



    return 0;
}
void print_as_asterix(int arr[], int length){
    int x;

    if(row < 10){
        printf("%d   -",row++);
    } else if(row <100){
        printf("%d  -",row++);
    } else if(row , 1000){
        printf("%d -",row++);
    }
    for(x=0; x<length;x++){
        if(arr[x]){
            printf("*");
        }else{
            printf(" ");
        }
    }
    printf("-\n");
}

int new_value(int rep[], int index){
    int nm1, np1, n;
    //corner cases.
    n = rep[index];
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


    int a,b,c;
    a= nm1;
    b= rep[index];
    c = np1;
    return (!a&&c)||(!a&&b)||(a&&!b&&!c);

}
