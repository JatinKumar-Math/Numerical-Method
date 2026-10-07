#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function representing dy/dx = f(x, y)
double f(double x, double y) {
    return (x + y);
}

int main() {
    double x, y, yNext, stepSize, targetX;
    
    cout << "Enter the starting point of x: ";
    cin >> x;
    cout << "Enter the value of y at starting point: ";
    cin >> y;
    cout << "Enter the step size: ";
    cin >> stepSize;
    cout << "Enter the target point you want the value at: ";
    cin >> targetX;

    cout << fixed << setprecision(8);

    int iterationCount = 0;
    cout << "\nIteration\t\tx\t\ty";
    cout << "\n" << iterationCount << "\t\t" << x << "\t" << y;

    while (x < targetX) {
        yNext = y + stepSize * f(x, y);
        x = x + stepSize;
        y = yNext;
        iterationCount++;
        cout << "\n" << iterationCount << "\t\t" << x << "\t" << y;
    }

    cout << endl;
    cout << "Value of y at " << targetX << " is " << y << endl;

    return 0;
}