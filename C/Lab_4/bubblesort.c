#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bubblesort.h"
#include "string.h"

void bubblesort(struct data *entry, int maxsize)
	{
		struct data temp;
		int maxpt;

		for(int i = (maxsize - 1); i > 0; i--)
			{
				maxpt = 0;
				for(int k = 1;k <= i;k++)
				{
					if(strcmp(entry[k].department, entry[maxpt].department) >0 )
						{
							maxpt = k;
						}
					temp = entry[maxpt];
					entry[maxpt] = entry[i];
					entry[i]=temp;
				}
			}
	}
 void swap(struct data *a, struct data *b)
	{
	    struct data tmp = *a;
	    *a = *b;
	    *b = tmp;
	}

 void bubblesortpointer(struct data *entry2, int maxsize)
	{
		int i, j;
		struct data temp;

		for (i = maxsize - 1; i >= 0; i--)
			{
	       		for (j = 0; j < i; j++)
	       			{
	            		if (strcmp(entry2[j].department, entry2[j + 1].department) > 0)
	           			 {
	               			 swap(&entry2[j], &entry2[j + 1]);
	            		 }
	        		}
    		}
	}

 void bubblesortaddress(struct data *entry3, int maxsize)
	{
		int i, j;
		struct data *entry3pt = entry3;
		for (i = maxsize - 1; i >= 0; i--)
			{
	       		for (j = 0; j < i; j++)
	       			{
	            		if (strcmp(((struct data)*(entry3+j)).department, ((struct data)*(entry3+j+1)).department) > 0)
	           			 {
	               			 swap((entry3+j), (entry3+j+1));

	            		 }
	        		}
    		}


	}

