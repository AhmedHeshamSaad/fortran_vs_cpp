#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    const int n = 10000, m = 10000;

    double** array1 = new double*[n];
    double** array2 = new double*[n];
    double** result = new double*[n];
    for (int i = 0; i < n; ++i) {
        array1[i] = new double[m];
        array2[i] = new double[m];
        result[i] = new double[m];
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array1[i][j] = i + j + 1;
            array2[i][j] = n - i + m - j - 1;
        }
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = array1[i][j] / 100.0 + pow(array2[i][j], 2.0) + sin(array1[i][j] / 100.0);
        }
    }
    auto finish = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = finish - start;
    cout << "Operation took " << elapsed.count() << " seconds.\n";

    // Optionally print some results
    cout << "Sample result: " << result[n-1][m-1] << endl;

    // Deallocate dynamic 2D arrays
    for (int i = 0; i < n; ++i) {
        delete[] array1[i];
        delete[] array2[i];
        delete[] result[i];
    }
    delete[] array1;
    delete[] array2;
    delete[] result;

    return 0;
}
