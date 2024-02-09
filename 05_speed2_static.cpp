#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

const int n = 10000;
const int m = 10000;
double array1[n][m];
double array2[n][m];
double result[n][m];

int main() {

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

    return 0;
}
