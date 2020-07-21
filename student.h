/* DO NOT MODIFY | NE MODIFIEZ PAS */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "support.h"

#define PI 3.14159265
#define WIDTH 3
#define GREYSCALE " .:-=+*#%@";
#define IMG_SIZE 42

// Question 1
float calculator(int choice, float a, float b);

// Question 2
double deg_to_rad(double deg);
double power(double x, double y);
double factorial(int x);
double sinus(double x, int n);

// Question 3
int *row_adder(int matrix[][WIDTH], int height);

// Question 4
void convert_to_ascii(int image[][IMG_SIZE], char ascii[][IMG_SIZE]);
void display_image(char ascii[][IMG_SIZE]);

#endif /* STUDENT_H_ */
