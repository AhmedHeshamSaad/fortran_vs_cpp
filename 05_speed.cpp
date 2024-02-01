#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

double trapezoidalRule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }
    return sum * h;
}

double f(double x) {
    return sin(x);
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    double integral = trapezoidalRule(f, 0, M_PI, 100000000);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Integral: " << integral << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
