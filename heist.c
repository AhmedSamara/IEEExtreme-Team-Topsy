#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int N;
	int M;
	char **loot;
	char **item;
	int *load;
	int *value;
	char **loadchar;
	char **valuechar;
	double *ratio;
	int *best;
	int *amount;
	int *singlevalue;
	double totalvalue;
	double totalload;
	scanf("%d", &N);
	scanf("%d", &M);

	char * temp;

	scanf("%s", temp);
	int i = 0;
	while (strcmp("END", temp) != 0) {
		loot[i] = temp;
		i++;
		scanf("%s", temp);
	}

    int k;
	for( k = 0; k < i; k++){
		item[i] = strtok(loot[i], ",");
		loadchar[i] = strtok(NULL, ",");
		sscanf(loadchar[i],"%d",&load[i]);
		valuechar[i] = strtok(NULL, ",");
		sscanf(valuechar[i],"%d",&value[i]);
		ratio[i] = (double)value[i] / (double)load[i];
	}

	totalload = (double)N * (double)M;
	int done[i];
	for(k = 0; k < i; k++) {
		done[k] = 0;
	}
	int first;
	int bestv;
	int biggest;
	int j;
	for(j = 0; j < i; j++){
		first = 1;
		int k;
		for(k = 0; k < i; k++){

			if((first == 1 || bestv < ratio[i]) && done[i] != 1){
				first = 0;
				biggest = k;
				bestv = ratio[k];
			}
		}
		done[biggest] = 1;
		best[j] = biggest;
	}

	int mathnum;

	for(k = 0; k < i; k++) {
		while(totalload - load[best[k]] >= 0) {
			totalload = totalload - load[best[k]];
			amount[best[k]] = amount[best[k]] + 1;
			singlevalue[best[k]] = singlevalue[best[k]] + (double)value[best[k]];
			totalvalue = totalvalue + (double)value[best[k]];
		}
	}
	for(k = 0; k < i; k++) {
		printf("hello");
	}
}
