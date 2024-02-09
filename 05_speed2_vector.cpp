#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    const int n = 10000, m = 10000;
    vector<vector<double>> array1(n, vector<double>(m)),
                                     array2(n, vector<double>(m)),
                                     result(n, vector<double>(m));

    // Initialize 2D arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array1[i][j] = i + j + 1;
            array2[i][j] = n - i + m - j - 1;
        }
    }

    auto start = chrono::high_resolution_clock::now();
    // Perform element-wise addition
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = array1[i][j] / 100.0 + pow(array2[i][j], 2.0) + sin(array1[i][j] / 100.0);
        }
    }
    auto finish = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = finish - start;
    cout << "Operation took " << elapsed.count() << " seconds.\n";

    return 0;
}
