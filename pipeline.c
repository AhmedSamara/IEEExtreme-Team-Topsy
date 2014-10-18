#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N;
struct BestChoice // creating a type struct
	{
	int min_cost;
	int next_row;
	int next_col;
	};

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    scanf("%d", &N);

    printf("N = %d\n",N);

    int city_grid[N][N];


    populate_array(city_grid);
    //
    print_array(city_grid);


    return 0;
}

int populate_array(int arr[N][N]){
    int row=0;
    int column=0;
    for(row=0; row < N;row++ ){
        for(column=0; column < N; column++){
            scanf("%d", &arr[row][column]);
        }
    }
}

int print_array(int arr[N][N]){

    int row=0;
    int column=0;

   for(row=0; row < N;row++ ){
        for( column=0; column < N; column++){

            printf("%d ", arr[row][column]);
        }
        printf("\n");
    }
}

struct BestChoice find_min(int grid[N][N],
                           int row_coord,
                           int col_coord){

    struct BestChoice NextPositionandCost;

    if(row_coord == 0)  // special case first time find lowest in the col
	{
    int i;
    //checks first column for winner.
	for(i=0; i<=N; i++)
		{
        //Only checks first column.
		if(NextPositionandCost.min_cost <= grid[i][0])
			{
			NextPositionandCost.min_cost =  grid[i][0];
			NextPositionandCost.next_row = i;
			NextPositionandCost.next_col = 1;
			}
		}
	return(NextPositionandCost);
	}
    else if(row_coord == N)   // corner case no rows below
	{
	if(NextPositionandCost.min_cost >= grid[row_coord+1][N-1])
		{
		NextPositionandCost.min_cost =  grid[i][1];
		NextPositionandCost.next_row = i;
		NextPositionandCost.next_col = 1;
		}
	if(NextPositionandCost.min_cost >= grid[row_coord][N])
		{
		NextPositionandCost.min_cost =  grid[i][1];
		NextPositionandCost.next_row = i;
		NextPositionandCost.next_col = 1;
		}
	}
    else if(row_coord == 1)   // corner case no rows above
        {
        }
    else if(col_coord == N)   // corner case we did it
        {
        }
    else
        {
        }
}
