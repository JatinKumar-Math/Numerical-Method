#include <iostream>
using namespace std;

float f(float x){
    return(1/(16+x*x));
}

int main(){
    float a, b;
    int n2;
    cout << "Enter the sub-interval for simpson 3/8 : ";
    cin >> n2;
    cout << "Enter the Lower limit : ";
    cin >> a;
    cout << "Enter the upper limit : ";
    cin >> b;

    if(n2 % 3 != 0){
        cout << "N must be a multiple of 3";
        return 0;
    }

    float sum1, sum2, a0, h, I;
    h = (b - a) / n2;
    sum1 = 0;
    sum2 = 0;
    
    for(int i = 1; i < n2; i++){
        a0 = a + i * h;
        if(i % 3 != 0){
            sum1 = sum1 + f(a0);
        }
        else{
            sum2 = sum2 + f(a0);
        }
    }
    I = (3 * h / 8) * (f(a) + f(b) + 3 * sum1 + 2 * sum2);
    
    cout << "Value of the integral by simpson 3/8 is :- " << I << endl;
    return 0;
}