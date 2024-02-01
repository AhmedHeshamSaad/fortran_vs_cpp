#include <cstdio>
#include <cmath>

int main() {
    // 1D static array
    int intArray[] = {1, 2, 3, 4, 5};
    const int arraySize = sizeof(intArray) / sizeof(intArray[0]);

    printf("Initial intArray: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Modify 1D array
    for (int i = 0; i < arraySize; ++i) {
        intArray[i] *= 2; // Double each element
    }
    printf("Modified intArray: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Static 2D array
    double matrix[2][4]; // Declared with fixed dimensions
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = i + j + 1; // Initialize elements
        }
    }

    // Print 2D array elements
    printf("2D array elements:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("(%d,%d): %.2f\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    // Perform operations on the 2D array
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = pow(matrix[i][j], 2.0) + matrix[i][j] / 2.0;
        }
    }

    // Print resulting matrix elements after operations
    printf("Resulting Matrix elements after operations:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("(%d,%d): %.2f\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    return 0;
}
