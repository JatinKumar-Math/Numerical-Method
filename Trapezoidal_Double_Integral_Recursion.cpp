#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y)
{
    return 1/(sqrt(x*x+y*y));
}

float inner(float x, float c, float d, int ny)
{
    float sum, h, y, I;

    h = (d-c)/ny;
    sum = 0;

    for(int i=1; i<ny; i++)
    {
        y = c+i*h;
        sum = sum + f(x,y);
    }

    I = (h/2)*(f(x,c)+f(x,d)+2*sum);

    return I;
}

float doubleIntegral(float a, float b, float c, float d, int ny, int nx)
{
    float h, sum, x, I;

    h = (b-a)/nx;
    sum = 0;

    for(int i=1; i<nx; i++)
    {
        x = a+i*h;
        sum = sum + inner(x,c,d,ny);
    }

    I = (h/2)*(inner(a,c,d,ny)+2*sum+inner(b,c,d,ny));

    return I;
}

int main()
{
    float a,b,c,d;
    int ny,nx;

    cout << "enter the lower limit of x: ";
    cin >> a;

    cout << "enter the upper limit of x: ";
    cin >> b;

    cout << "enter the interval for x: ";
    cin >> nx;

    cout << "enter the lower limit of y: ";
    cin >> c;

    cout << "enter the upper limit of y: ";
    cin >> d;

    cout << "enter the interval for y: ";
    cin >> ny;

    float I = doubleIntegral(a,b,c,d,ny,nx);

    cout << I;

    return 0;
}