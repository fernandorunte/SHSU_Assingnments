#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fica.h"


float fica;


float calculateFica(float ytd, float gross)
{
	float rate=0.071;

	if(ytd<110,100.00)
		{
			if(ytd+gross>110,000.00)
			{
				fica=(((110,100.00)-ytd)*rate);
			}

			else
			{
				fica=(gross*rate);
			}

		}

		else
		{
			fica=0;
		}


	return fica;

}