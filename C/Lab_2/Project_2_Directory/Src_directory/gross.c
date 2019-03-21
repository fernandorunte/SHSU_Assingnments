#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gross.h"


float gross;

float calculateGross(float hours, float payrate)
{
	gross=(hours>40)?(((hours-40.0)*1.5*payrate)+40.0*payrate):(hours*payrate);

	return gross;

}
