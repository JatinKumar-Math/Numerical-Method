// Double integral using 2D Trapezoidal Rule
#include <iostream>
using namespace std;

float f(float x, float y)
{
    return 1 / (x + y);
}

int main()
{
    float a, b, c, d, h, k, x, y, sum = 0;
    int nx, ny;

    cout << "Enter lower limit of x: ";
    cin >> a;

    cout << "Enter upper limit of x: ";
    cin >> b;

    cout << "Enter number of subintervals for x: ";
    cin >> nx;

    cout << "Enter lower limit of y: ";
    cin >> c;

    cout << "Enter upper limit of y: ";
    cin >> d;

    cout << "Enter number of subintervals for y: ";
    cin >> ny;

    h = (b - a) / nx;
    k = (d - c) / ny;

    for (int i = 0; i <= nx; i++)
    {
        x = a + i * h;

        for (int j = 0; j <= ny; j++)
        {
            y = c + j * k;

            float w = 1;

            if (i == 0 || i == nx)
                w = w * 0.5;

            if (j == 0 || j == ny)
                w = w * 0.5;

            sum = sum + w * f(x, y);
        }
    }

    float I = h * k * sum;

    cout << "Value of double integral = " << I;

    return 0;
}
