#include <iostream>
using namespace std;

float f(float x){
    return(1/(16+x*x));
}

int main(){
    float a, b;
    int n1;
    cout << "Enter the sub-interval for simpson 1/3 : ";
    cin >> n1;
    cout << "Enter the Lower limit : ";
    cin >> a;
    cout << "Enter the upper limit : ";
    cin >> b;

    if(n1 % 2 != 0){
        cout << "N must be an even number";
        return 0;
    }

    float sum1, sum2, a0, h, I;
    h = (b - a) / n1;
    sum1 = 0;
    sum2 = 0;
    
    for(int i = 1; i < n1; i++){
        a0 = a + i * h;
        if(i % 2 != 0){
            sum1 = sum1 + f(a0);
        }
        else{
            sum2 = sum2 + f(a0);
        }
    }
    I = (h / 3) * (f(a) + f(b) + 4 * sum1 + 2 * sum2);
    
    cout << "Value of the integral by simpson 1/3 is :- " << I << endl;
    return 0;
}