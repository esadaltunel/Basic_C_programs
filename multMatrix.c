#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **matrix, **matrix2, **concMatrix;
int i, j, k, row, row2, column, column2, sum;

// Function for printing matrix
void show(int** matrix, int row, int column){
    for (i = 0; i < row; i++) {
        
        for (j = 0; j < column; j++) {
            
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}



// Function for adding random value in matrix
void add(int **matris, int row, int column){
    for (i = 0; i < row; i++) {
        
        for (j = 0; j < column; j++) {
            matris[i][j] = rand() % 100;
            
        }
    }
}

// Function for multiplication
void mult(int** matrix1,int** matrix2, int row1,
          int row2, int column2){
    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            for (k = 0; k < row2; k++) {
                sum += matrix1[i][k]*matrix2[k][j];
            }
            concMatrix[i][j] = sum;
            sum = 0;
        }
    }
}


int main(){
    
    printf("1. Row number: ");
    scanf("%d", &row);
    printf("1. Column number: ");
    scanf("%d", &column);
    printf("2. Row number: ");
    scanf("%d", &row2);
    printf("2. Column number: ");
    scanf("%d", &column2);
//  Parameters recived for 'matrix' and 'matrix2'
    
    
    if (column == row2) {
        printf("\n");
    } else {
        exit(1);
    }
    matrix = (int**)malloc(sizeof(int*)*row);
    matrix2 = (int**)malloc(sizeof(int*)*row2);
    concMatrix = (int**)malloc(sizeof(int*)*row);
    for (i = 0; i < column; i++) {
        matrix[i] = (int*)malloc(sizeof(int)*column);
    }
    
    for (i = 0; i < column2; i++) {
        matrix2[i] = (int*)malloc(sizeof(int)*column2);
    }
    
    for (i = 0; i < column2; i++) {
        concMatrix[i] = (int*)malloc(sizeof(int)*column2);
    }
//  2D 'matrix' and 'matrix2' created.
    

    add(matrix, row, column);
    add(matrix2, row2, column2);
//  Random values added in the matrix
    

    printf("Matrices to multiplication\n\nMatrix 1:\n");
    show(matrix, row, column);
    printf("\nMatrix 2:\n");
    show(matrix2, row2, column2);
    printf("\nConclution of multiplication: \n\n");
    mult(matrix, matrix2, row, row2, column2);
    show(concMatrix, row, column2);
    printf("\n");
    
    free(matrix);
    free(matrix2);
    free(concMatrix);


    
}
