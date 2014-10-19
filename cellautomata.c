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
    int pick[N];
    int x;
    for(x=0;x<N;x++){
        scanf("%d", &pick[x]);
    }
    for(x=0;x<N;x++){
        printf("%d", pick[x]);
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
