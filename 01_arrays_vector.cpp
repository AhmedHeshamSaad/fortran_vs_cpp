#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 1D array
    vector<int> intArray = {1, 2, 3, 4, 5};
    printf("Initial intArray: ");
    for (int val : intArray) {
        printf("%d ", val);
    }
    printf("\n");

    // Modify 1D array
    // use a reference to modify
    for (int& val : intArray) {
        val *= 2; // Double each element
    }
    printf("Modified intArray: ");
    for (int val : intArray) {
        printf("%d ", val);
    }
    printf("\n");

    // 2D array using vector of vectors
    int rows = 2, cols = 4;
    vector<vector<double>> matrix(rows, vector<double>(cols));
    // Initialize 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i + j + 1; // Adjust for 0-based indexing
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

    return 0;
}
