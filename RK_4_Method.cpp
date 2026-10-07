#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function representing dy/dx = f(x, y)
double f(double x, double y) {
    return (x + y);
}

int main() {
    double x, y, z, h, x1;
    double k1, k2, k3, k4;

    cout << "Enter the starting point of x: ";
    cin >> x;
    cout << "Enter the value of y at starting point: ";
    cin >> y;
    cout << "Enter the step size: ";
    cin >> h;
    cout << "Enter the target point you want the value at: ";
    cin >> x1;

    cout << fixed << setprecision(8);

    int n = 0;
    cout << "\nIteration\t\tx\t\ty";
    cout << "\n" << n << "\t\t" << x << "\t" << y;

    while (x < x1) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        k4 = h * f(x + h, y + k3);

        z = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;
        y = z;
        n++;
        
        cout << "\n" << n << "\t\t" << x << "\t" << y;
    }

    cout << endl;
    cout << "Value of y at " << x1 << " is " << y << endl;

    return 0;
}