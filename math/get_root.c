#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, double *argv)
{
	double function(double x)
	{
		return x+(sin(3*x));
	}
	double deriv(double x)
	{
		double h = 0.00001;
		return (function(x + h) - function(x))/h;
	}
	
	double x = argv[1];

	while (abs(function(x)) >= 0.00001)
	{
		x = x - function(x)/deriv(x);
		printf("\n%f\n",x );
	}
	printf("The root searched for is x = %f\n",x);

	
}
