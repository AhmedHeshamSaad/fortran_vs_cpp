#include <cstdio>
#include <cmath>

int main() {
    // 1D dynamic array
    int* intArray = new int[5]{1, 2, 3, 4, 5};
    
    printf("Initial intArray: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Modify 1D array
    for (int i = 0; i < 5; ++i) {
        intArray[i] *= 2; // Double each element
    }
    printf("Modified intArray: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Free the 1D array
    delete[] intArray;

    // 2D dynamic array
    int rows = 2, cols = 4;
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols]; // Allocate each row
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i + j + 1; // Initialize elements
        }
    }

    // Print 2D array elements
    printf("2D array elements:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("(%d,%d): %.2f\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    // Perform operations on the 2D array and print results
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = pow(matrix[i][j], 2.0) + matrix[i][j] / 2.0;
        }
    }
    printf("Resulting Matrix elements after operations:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("(%d,%d): %.2f\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    // Free the 2D array
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; // Free each row
    }
    delete[] matrix; // Free the array of pointers

    return 0;
}
