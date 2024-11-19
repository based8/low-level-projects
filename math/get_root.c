#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	double function(double x)
	{
		// Here you can change the function you want to get the root of
		// remember to use parantheses correctly, it can get messy
		return (pow(x,2)-(3*x))-(cos(x));
	}
	double deriv(double x)
	{
		double h = 0.00001;
		return (function(x + h) - function(x))/h;
	}

	printf(argv[1]);
	if (argv[1] != NULL)
	{
		size_t argsize = sizeof(argv[1])/sizeof(char);
		char arg[argsize];
		memcpy(&arg, argv[1], sizeof(argv[1]));
		
		for (int i = 0; i < argsize; i++)
		{
			printf(arg);
		}
	}

	double x = 0.5;

	while (abs(function(x)) >= 0.00001)
	{
		x = x - function(x)/deriv(x);
		printf("\n%f\n",x );
	}
	printf("The root searched for is x = %f\n",x);

	
}
