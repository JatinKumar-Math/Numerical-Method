#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y)
{
    return 1/(sqrt(x*x+y*y));
}

float inner(float x, float c, float d, int ny)
{
    float sum, h, y, I,sum1,sum2;
    h = (d-c)/ny;
    sum1 = 0;
    sum2 = 0;

    for(int i=1; i<ny; i++)
    {
        y = c+i*h;
        if(i % 2 != 0){
            sum1 = sum1 + f(x,y);
        }
        else{
            sum2 = sum2 + f(x,y);
        }
    }

    I = (h/3)*(f(x,c)+f(x,d)+4*sum1+2*sum2);

    return I;
}

float doubleIntegral(float a, float b, float c, float d, int ny, int nx)
{
    if(nx%2!=0 || ny%2!=0){
        return 0;
    }
    float h, sum, x, I,sum1,sum2; 

    h = (b-a)/nx;
    sum1 = 0;
    sum2 = 0;

    for(int i=1; i<nx; i++)
    {
        x = a+i*h;
        if(i % 2 != 0){
            sum1 = sum1 + inner(x,c,d,ny);
        }
        else{
            sum2 = sum2 + inner(x,c,d,ny);
        }
       
    }

    I = (h/3)*(inner(a,c,d,ny)+4*sum1+2*sum2+inner(b,c,d,ny));

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