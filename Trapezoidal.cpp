#include <iostream>
using namespace std;

float f(float x){
    return(1/(16+x*x));
}

int main(){
    float a, b;
    int n;
    cout << "Enter the sub-interval for trapezoidal : ";
    cin >> n;
    cout << "Enter the Lower limit : ";
    cin >> a;
    cout << "Enter the upper limit : ";
    cin >> b;

    float sum, h, a0, I;
    h = (b - a) / n;
    a0 = a + h;
    sum = 0;
    while(a0 < b){
        sum = sum + f(a0);
        a0 = a0 + h;
    }
    I = (h / 2) * (f(a) + f(b) + 2 * sum);
    
    cout << "Value of the integral by trapezoidal is :- " << I << endl;
    return 0;
}