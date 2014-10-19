
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANCHOVIES 50
#define ARTICHOKE 60
#define BACON 92
#define BROCCOLI 24
#define CHEESE 80
#define CHICKEN 30
#define FETA 99
#define GARLIC 8
#define HAM 46
#define JALAPENO 5
#define MEATBALLS 120
#define MUSHROOMS 11
#define OLIVES 25
#define ONIONS 11
#define PEPPERONI 80
#define PEPPERS 60
#define PINEAPPLE 21
#define RICOTTA 108
#define SAUSAGE 115
#define SPINACH 18
#define TOMATOES 14
#define PIZZA 270

int main () {
	int pizzaCombos;
	char * pizzaString;
	int calories = 0;

	scanf("%d", &pizzaCombos);
	if(pizzaCombos > 100) {
		pizzaCombos = 100;
	}
	char pizzaToppings[pizzaCombos][10];
	int pizzaSlices[pizzaCombos];

    int i;
	for( i = 0; i < pizzaCombos; i++) {
		scanf("%d", &pizzaSlices[i]);
		scanf("%s", pizzaToppings[i]);

		pizzaString = strtok(pizzaToppings[i], " ,");
		while(pizzaString != NULL) {
			if(strcmp("Anchovies", pizzaString) == 0) {
				calories = calories + (ANCHOVIES * pizzaSlices[i]);
			} else
			if((strcmp("Artichoke", pizzaString) == 0) || (strcmp("Peppers", pizzaString) == 0)) {
				calories = calories + (ARTICHOKE * pizzaSlices[i]);
			} else
			if(strcmp("Bacon", pizzaString) == 0) {
				calories = calories + (BACON * pizzaSlices[i]);
			} else
			if(strcmp("Broccoli", pizzaString) == 0) {
				calories = calories + (BROCCOLI * pizzaSlices[i]);
			} else
			if((strcmp("Cheese", pizzaString) == 0) || (strcmp("Pepperoni", pizzaString) == 0)) {
				calories = calories + (CHEESE * pizzaSlices[i]);
			} else
			if(strcmp("Chicken", pizzaString) == 0) {
				calories = calories + (CHICKEN * pizzaSlices[i]);
			} else
			if(strcmp("Feta", pizzaString) == 0) {
				calories = calories + (FETA * pizzaSlices[i]);
			} else
			if(strcmp("Garlic", pizzaString) == 0) {
				calories = calories + (GARLIC * pizzaSlices[i]);
			} else
			if(strcmp("Ham", pizzaString) == 0) {
				calories = calories + (HAM * pizzaSlices[i]);
			} else
			if(strcmp("Jalapeno", pizzaString) == 0) {
				calories = calories + (JALAPENO * pizzaSlices[i]);
			} else
			if(strcmp("Meatballs", pizzaString) == 0) {
				calories = calories + (MEATBALLS * pizzaSlices[i]);
			} else
			if((strcmp("Mushrooms", pizzaString) == 0) || (strcmp("Onions", pizzaString) == 0)) {
				calories = calories + (MUSHROOMS * pizzaSlices[i]);
			} else
			if(strcmp("Olives", pizzaString) == 0) {
				calories = calories + (OLIVES * pizzaSlices[i]);
			} else
			if(strcmp("Pineapple", pizzaString) == 0) {
				calories = calories + (PINEAPPLE * pizzaSlices[i]);
			} else
			if(strcmp("Ricotta", pizzaString) == 0) {
				calories = calories + (RICOTTA * pizzaSlices[i]);
			} else
			if(strcmp("Sausage", pizzaString) == 0) {
				calories = calories + (SAUSAGE * pizzaSlices[i]);
			} else
			if(strcmp("Spinach", pizzaString) == 0) {
				calories = calories + (SPINACH * pizzaSlices[i]);
			} else
			if(strcmp("Tomatoes", pizzaString) == 0) {
				calories = calories + (TOMATOES * pizzaSlices[i]);
			}
			pizzaString = strtok(NULL, ",");

		}
		calories = calories + pizzaSlices[i] * PIZZA;
	}

	printf("The total calorie intake is %d", calories);
	return 0;

}
