#include <stdio.h>

#define MAX_SIZE 100

void calculateRowColumnSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Calculate and print row sums
    printf("Row sums:\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }
    
    // Calculate and print column sums
    printf("\nColumn sums:\n");
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, colSum);
    }
}

int main() {
    int rows, cols;
    
    scanf("%d", &rows);
    scanf("%d", &cols);
    
    int matrix[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    calculateRowColumnSum(matrix, rows, cols);
    
    return 0;
}