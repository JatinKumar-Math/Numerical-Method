#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y)
{
	return (x*x+y*y-4);
}

float g(float x, float y)
{
	return (x-y);
}

float fx(float x, float y)
{
	return (2*x);
}

float fy(float x, float y)
{
	return (2*y);
}

float gx(float x, float y)
{
	return (1);
}

float gy(float x, float y)
{
	return (-1);
}

float D(float x, float y)
{
	return(fx(x,y)*gy(x,y)-gx(x,y)*fy(x,y));
}

float Dx(float x, float y)
{
	return(f(x,y)*gy(x,y)-g(x,y)*fy(x,y));
}

float Dy(float x, float y)
{
	return(fx(x,y)*g(x,y)-gx(x,y)*f(x,y));
}

int main()
{
	float x0,y0,epsilon,h,k,x1,y1;
	
	cout<<"Enter the initial guess for x and y : ";
	cin>>x0>>y0;
	cout<<"Enter the tolerance error : ";
	cin>>epsilon;
	float error1 =1;
    float error2  =1;
      int iteration = 0;
	
	while(error1 >epsilon || error2 >epsilon)
	{
		h=-Dx(x0,y0)/D(x0,y0);
	    k=-Dy(x0,y0)/D(x0,y0);
	    x1=x0+h;
      	y1=y0+k;
        error1=fabs(x1-x0);
        error2=fabs(y1-y0);
        x0=x1;
		y0=y1;
        iteration++;
		cout<<"x"<<iteration<<" = "<<x0<<"\t y"<<iteration<<" = "<<y0<<endl;
	}
	
	cout<<"The roots of the equation are: "<<x0<<","<<y0;
	
	
	
}