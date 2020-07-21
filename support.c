/* DO NOT MODIFY | NE MODIFIEZ PAS */

/*
 * The functions below are provided for you to use
 */

#include <stdlib.h>
#include <stdio.h>
#include "support.h"

float addition(float a, float b) {
	return a + b;
}

float difference(float a, float b) {
	return a - b;
}

float multiplication(float a, float b) {
	return a * b;
}

float division(float a, float b) {
	return a / b;
}

void interface_calc(int *choice, float *a, float *b) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf(
			"Choose between the following option:\n1. Addition\n2. Subtration\n3. Multiplication\n4. Division\n");
	scanf("%d", choice);
	printf("Enter the 2 operands:\n");
	scanf("%f %f", a, b);
}

void display_row_matrix(int *matrix, int size) {
	if (matrix == NULL) {
		return;
	}
	printf("[\n");
	for (int i = 0; i < size; i++) {
		printf("%d\n", matrix[i]);
	}
	printf("]\n");
}
