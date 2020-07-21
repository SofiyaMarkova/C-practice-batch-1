#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float calculator(int choice, float a, float b) {
    // yours | a vous
    //switch statement here not need break because each case has a return to make it go away (can't run another case)
    switch (choice) {
        case 1: //add
            return addition(a, b);

        case 2: //subtract
            return difference(a, b);

        case 3: //multiply
            return multiplication(a, b);

        case 4: //divide
            return division(a, b);

        default:
            printf("no valid operation was inputed. choice only takes 1 to 4\n");
            return 0.0;

    }
}

double deg_to_rad(double deg) {
    // yours | a vous
    return deg * (PI / 180);
}

double power(double x, double y) { //x to the power of y
    // yours | a vous
    double result = x; //makes so starts with result being x as the base we will mult with
    if (y == 0) {  //to power of 0
        result = 1;
    } else if (y < 0) { //to power (-) num
        y = -y; //make y flip sign, so like absolute
        return (1 / power(x, y));
    } else { //to power (+) num
        for (int i = 1; i < y; i++) {
            result = result * x;
        }
    }
    return result;
}

double factorial(int x) {
    // yours | a vous
    double fact = x;
    // shows error if the user enters a negative integer, because can't do factorial of negative number
    if (x < 0)
        printf("factorial of a negative number doesn't exist");
    else if (x == 1) {
        fact = 1; //factorial of 0 is 1
    } else {
        for (int i = 1; i < x; i++) {
            fact *= i;
        }
    }
    return fact;
}

double sinus(double x, int n) {
    // yours | a vous
    //convert degrees angle to radians angle using the function implemented
    //convert the given angle to degrees
    x = deg_to_rad(x);
    double sum = 0.0; //to store sum
//implementing the function
    for (int i = 0; i < n; i++) {
        sum = sum + (power(-1, i) / factorial(2 * i + 1)) * (power(x, 2 * i + 1));
    }
    return sum;
}

int *row_adder(int matrix[][WIDTH], int height) {
    // yours | a vous
    int *total = calloc(height, sizeof(int)); //declare array on heap with malloc (rather than on stack usual way)
    /*what happening:
     * malloc allocates memory on the heap. it allocates height * sizeof( int ) of memory. which is height times the amount of bytes needed for an int
     * so allocates height amount of int (byte spaces)
     * then returns a void pointer to the stack. on the stack a pointer called array of type int* takes the void pointer.
     * int pointer now points to the memory address on the heap. void pointer acts as just a memory address (of what type no matter because int pointer on stack determines it is for int)
     *
     *int* pointer called array knows to read by int because the int pointer knows to move over 4 bytes each time to count as an int (during whatever memory was allocated with malloc now given)
     */

//traverse given matrix by row and col
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < WIDTH; col++) {
            total[row] += matrix[row][col]; //add up all the matrix values for the corresponding row into the location of the array (created as pointer)
        }
    }
    return total; //return the array (see how return type is an int, with the *. the * is just on the name of the function but actually means that return and int*, int pointer)
    //and it is correct, because in this function created and int pointer (called array). that now can return. after it has done the operation
}

void convert_to_ascii(int image[][IMG_SIZE], char ascii[][IMG_SIZE]) {
    // yours | a vous
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            if (image[i][j] >= 0 && image[i][j] < 25) {
                ascii[i][j] = '@';

            } else if (image[i][j] >= 26 && image[i][j] < 51) {
                ascii[i][j] = '%';
            } else if (image[i][j] >= 52 && image[i][j] < 77) {
                ascii[i][j] = '#';
            } else if (image[i][j] >= 78 && image[i][j] < 103) {
                ascii[i][j] = '*';
            } else if (image[i][j] >= 104 && image[i][j] < 155) {
                ascii[i][j] = '+';
            } else if (image[i][j] >= 156 && image[i][j] < 181) {
                ascii[i][j] = '-';
            } else if (image[i][j] >= 182 && image[i][j] < 207) {
                ascii[i][j] = ':';
            } else if (image[i][j] >= 208 && image[i][j] < 233) {
                ascii[i][j] = '.';
            } else if (image[i][j] >= 234 && image[i][j] < 259) {
                ascii[i][j] = ' ';
            }
        }
    }

}

void display_image(char ascii[][IMG_SIZE]) {
    /* Your code here */
    //just loops through ascii 2D array to print it all
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}
