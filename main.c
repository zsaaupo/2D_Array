#include <stdio.h>
#include <limits.h> //it helps us to get the Maximum integer value (INT_MAX)

// Define Rows as R and Columns as C
#define R 5
#define C 4

// Global variable
int i, j;
// pointer
int *p;

// prototypes
void addData(int matrix[R][C]);

void print2Darray(int matrix[R][C]);

int sumAllValueOf2Darray(int matrix[R][C]);

int maxValue(int matrix[R][C]);
int minValue(int matrix[R][C]);

void sumMatrix(int sumMatrix[R][C], int Matrix1[R][C], int Matrix2[R][C]);


char main(){

    int matrixA[R][C];
    int matrixB[R][C];


    // Add data to 2D array by calling addData() function
    addData(matrixA);
    addData(matrixB);


    // printing all data of 2D array by calling print2Darray() function
    printf("\n\nAll value of MatrixA\n\n");
    print2Darray(matrixA);

    printf("\n\nAll value of MatrixB\n\n");
    print2Darray(matrixB);


    // printing Sum of all data of a 2D array by calling sumAllValueOf2Darray() function
    printf("\n\nSum of matrixA : %d\n\n", sumAllValueOf2Darray(matrixA));
    printf("\n\nSum of matrixB : %d\n\n", sumAllValueOf2Darray(matrixB));

    //printing maximum and minimum value of 2D array by calling maxValue() & minValue() function

    printf("\n\nMaximum value of matrixA: %d\n", maxValue(matrixA));
    printf("Minimum value of matrixA:%d\n\n", minValue(matrixA));

    printf("\n\nMaximum value of matrixB: %d\n", maxValue(matrixB));
    printf("Minimum value of matrixB:%d\n\n", minValue(matrixB));


    int matrixC[R][C];

    //Create 2D array of element-wise sum of two tow 2D array
    sumMatrix(matrixC, matrixA, matrixB);

    printf("\n\nAll value of MatrixC\n\n");
    print2Darray(matrixC);

    return 'ZSA';
}


// User define functions

// add data to predefine 2D array by using user input & for loop
void addData(int matrix[R][C]){

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("Enter valuer for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


// print 2D array's all data using Pointer & for loop
void print2Darray(int matrix[R][C]){

    p = &matrix[0][0];
    for(p, i = 0; p <= &matrix[R][C] && i < R * C ; p++, i++){
        printf("%d\n", *p);
    }
}


// Return sum of all data from a 2D array by using Pointer & for loop
int sumAllValueOf2Darray(int matrix[R][C]){
    int sum;
    p = &matrix[0][0];
    for(p, i = 0; p <= &matrix[R][C] && i < R * C ; p++, i++){
        sum = sum + *p;
    }
    return sum;
}


// Return maximum value of a 2D array by using Pointer, for loop & IF statement
int maxValue(int matrix[R][C]){

    int max = 0;

    p = &matrix[0][0];
    for(p, i = 0; p <= &matrix[R][C] && i < R * C ; p++, i++){

        if(*p > max){
            max = *p;
        }
    }
    return max;
}

// Return minimum value of a 2D array by using Pointer, for loop & IF statement
int minValue(int matrix[R][C]){

    int min = INT_MAX;
    p = &matrix[0][0];

    for(p, i = 0; p <= &matrix[R][C] && i < R * C ; p++, i++){

        if(*p < min){
            min = *p;
        }
    }
    return min;
}


// Calculates the element-wise sum of two matrices and stores the result in a third matrix by using Pointer & for loop
void sumMatrix(int sumMatrix[R][C], int Matrix1[R][C], int Matrix2[R][C]){

    int *A, *B;
    A = &Matrix1[0][0];
    B = &Matrix2[0][0];

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            sumMatrix[i][j] = *A + *B;
            A++, B++;
        }
    }
}
