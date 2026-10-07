#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return (x + y);
}

int main() {
    double x, y, z, h, x1;
    double old_z, error, tolerance;
    int maxIterations; 
    cout << "Enter the starting point of x: ";
    cin >> x;
    cout << "Enter the value at point x: ";
    cin >> y;
    cout << "Enter the step size: ";
    cin >> h;
    cout << "Enter the point u want the value: ";
    cin >> x1;
    cout << "Enter the error tolerance: ";
    cin >> tolerance;
    cout << "Enter max corrector iterations (safeguard): ";
    cin >> maxIterations;

    cout << fixed << setprecision(8);

    int n = 0;
    cout << "\nIteration\t\tx\t\tPredictor_y\t\tCorrected_y";
    cout << "\n" << n << "\t\t" << x << "\t\t-\t\t\t" << y;

    while (x < x1) {
        
        z = y + h * f(x, y);
        double predictor_y = z; 
        
        error = 1.0;
        int iterCount = 0; 

        
        while (error > tolerance && iterCount < maxIterations) {
            old_z = z;
            z = y + (h / 2.0) * (f(x, y) + f(x + h, z));
            error = fabs(z - old_z);
            iterCount++;
        }

        x = x + h;
        y = z;
        n++;
        
        cout << "\n" << n << "\t\t" << x << "\t\t" << predictor_y << "\t\t" << y;
    }

    cout << endl;
    cout << "Value of y at " << x1 << " is " << y << endl;

    return 0;
}