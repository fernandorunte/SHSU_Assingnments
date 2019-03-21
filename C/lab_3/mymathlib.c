
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#define EPISILON 0.0000001;





void sphere(float radius, float *surface, float *volume)
{

	*surface=(((double)4)*M_PI*(radius*radius));
	*volume=((((double)4)*M_PI*(radius*radius*radius))/((double)3));


}

float volCylinder(float radius, float height)
{
	float volume=0.0;
	volume=(M_PI*radius*radius*height);
	return (volume);
}


float sumFloats(float arrayofFloats[], int numFloats)
{
	float sum=0.0;

	for( int i = 0; i < numFloats; i++)
		{
			sum = arrayofFloats[i] + sum;												//sums data in array
		}

	return (sum);
}

double sine(float angle)	//input is in radians as it was converted in main
{
	int i,n;
	int sign = -1;
	double sum = angle;
	double power=angle;
	double fact = 1.0;
	double psum=0.0;

	for (i = 1; fabs(fabs(sum) - fabs(psum)) > 0.0000000001; ++i)
		{
			psum = sum;
			power = power * angle *angle;
			n = (2*i+1);
			fact = fact * n * (n-1);
			sum += sign * power/fact;
			sign = -sign;
		}
	return (sum);
}

