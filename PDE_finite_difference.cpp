
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double P(double x) {
    return 0;
}

double Q(double x) {
    return 0;
}

double R(double x) {
    return -2;
}

int main() {
    int n;
    double a0, b0, ya, yb;

    double a[100], b[100], c[100], d[100];
    double x[100], alpha[100], beta[100];

    cout << "Enter the number of intervals: ";
    cin >> n;

    cout << fixed << setprecision(5);

    a0 = ya = yb = 0;
    b0 = 1;

    if (n < 2 || n > 99) {
        cout << "Number of intervals must be between 2 and 99.";
        return 0;
    }

    double h = (b0 - a0) / n;
    cout << "Step size is " << h << endl;

    int m = n - 1;

    // Form the finite difference equations
    for (int i = 1; i <= m; i++) {
        double xi = a0 + i * h;

        double Pi = P(xi);
        double Qi = Q(xi);
        double Ri = R(xi);

        a[i] = 1 - h * Pi / 2;
        b[i] = -2 + h * h * Qi;
        c[i] = 1 + h * Pi / 2;
        d[i] = h * h * Ri;
    }

    // Apply boundary conditions
    d[1] = d[1] - a[1] * ya;
    d[m] = d[m] - c[m] * yb;

    // Thomas algorithm: forward elimination
    alpha[1] = b[1];
    beta[1] = d[1] / alpha[1];

    for (int i = 2; i <= m; i++) {
        alpha[i] = b[i] -
                   (a[i] * c[i - 1]) / alpha[i - 1];

        beta[i] = (d[i] - a[i] * beta[i - 1])
                  / alpha[i];
    }

    // Back substitution
    x[m] = beta[m];

    for (int i = m - 1; i >= 1; i--) {
        x[i] = beta[i] -
               (c[i] * x[i + 1]) / alpha[i];
    }

    // Display the solution
    cout << "\nSolution is\n";
    cout << "x\t\ty(x)\n";

    cout << a0 << "\t\t" << ya << "\n";

    for (int i = 1; i <= m; i++) {
        double xi = a0 + i * h;
        cout << xi << "\t\t" << x[i] << "\n";
    }

    cout << b0 << "\t\t" << yb << "\n";

    return 0;
}
