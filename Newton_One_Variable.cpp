#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
    return x*x*x - 3*x - 5;
}
float fx(float x)
{
    return 3*x*x - 3;
}
int main()
{
    float epsilon;
    float x0;
    cout << "Enter the initial guess of x: ";
    cin >> x0;
    cout << "Enter the tolerance error: ";
    cin >> epsilon;
    float error = 1;
    int iteration = 0;
    while(error > epsilon)
    {
        float x1 = x0 - (f(x0) / fx(x0));
        error = fabs(x1 - x0);
        x0 = x1;
        iteration++;
        cout<<"x"<<iteration<<" = "<<x0<<endl;  
    }
    cout << "The root of the equation is : " << x0 << endl;
    return 0;
}
