#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bubblesort.h"		//user created library for lab optin "B"




void placeintoarray(struct data *entry2, int maxsize)						//load data into array of structs for entry2
	{

		FILE *inFile;														//logical input file in program
		inFile = fopen("datafile.txt", "r");


		char surname[35];
		char givenname[35];
		char department[35];
		float payrate;
		char eyecolor[35];

		for(int i = 0;((fscanf(inFile, "%s%s%s%f%s", surname, givenname, department, &payrate, eyecolor ))!=EOF); i++)
			{
				strcpy(entry2[i].surname, surname);
				strcpy(entry2[i].givenname, givenname);
				strcpy(entry2[i].department, department);
				entry2[i].payrate = payrate;
				strcpy(entry2[i].eyecolor, eyecolor);
			}
		fclose(inFile);
	}


void placeintoarray2(struct data *entry3, int maxsize)						//load data into array of structs for entry3
	{

			FILE *inFile;													//logical input file in program
			inFile = fopen("datafile.txt", "r");


			char surname[35];
			char givenname[35];
			char department[35];
			float payrate;
			char eyecolor[35];

			for(int i = 0;((fscanf(inFile, "%s%s%s%f%s", surname, givenname, department, &payrate, eyecolor ))!=EOF); i++)
				{
					strcpy(entry3[i].surname, surname);
					strcpy(entry3[i].givenname, givenname);
					strcpy(entry3[i].department, department);
					entry3[i].payrate = payrate;
					strcpy(entry3[i].eyecolor, eyecolor);
				}
			fclose(inFile);
	}

int main()
{
	struct data entry[28];
	struct data entry2[28];
	struct data	entry3[28];


	FILE *inFile;													//logical input file in program
	inFile = fopen("datafile.txt", "r");
	FILE *outFile;													//logical input file in program
	outFile = fopen("reportfile.txt", "w");

	char surname[35];
	char givenname[35];
	char department[35];
	float payrate;
	char eyecolor[35];

		for(int i = 0;((fscanf(inFile, "%s%s%s%f%s", surname, givenname, department, &payrate, eyecolor ))!=EOF); i++)
			{
				strcpy(entry[i].surname, surname);
				strcpy(entry[i].givenname, givenname);
				strcpy(entry[i].department, department);																	//placing data into array
				entry[i].payrate = payrate;
				strcpy(entry[i].eyecolor, eyecolor);
			}


		fprintf(outFile, "----------------Raw unsorted data----------------\n");
		for(int i = 0; i < sizeof(entry) / sizeof(*entry); i++)																//printing unsorted data
			{

		 		fprintf(outFile,"%s, ", entry[i].surname);
				fprintf(outFile,"%s, ", entry[i].givenname);
				fprintf(outFile,"%s, ", entry[i].department);
				fprintf(outFile,"%0.2f, ", entry[i].payrate);
				fprintf(outFile,"%s. \n", entry[i].eyecolor);
			}


	bubblesort(entry, sizeof(entry) / sizeof(*entry));																		//sort by department using physical replacement of struc

	fprintf(outFile, "----------------“D” option sorted results:----------------\n");
	for (int i = 0; i < 28; i++)																							//prints sorted data from regular bubble sort
 	{
        fprintf(outFile,"%s, %s, %s, %0.2f, %s.\n", entry[i].surname, entry[i].givenname, entry[i].department, entry[i].payrate, entry[i].eyecolor);
   	}


	placeintoarray(entry2, sizeof(entry2) / sizeof(*entry2));																//places data into array
	bubblesortpointer(entry2, sizeof(entry2) / sizeof(*entry2));															//sort by department using pointers
	fprintf(outFile, "----------------“C” option sorted results done by pointer sort:----------------\n");
 	for (int i = 0; i < 28; i++)																							//prints sorted data by pointer
 	{
        fprintf(outFile,"%s, %s, %s, %0.2f, %s.\n", entry2[i].surname, entry2[i].givenname, entry2[i].department, entry2[i].payrate, entry2[i].eyecolor);
   	}


	placeintoarray(entry3, sizeof(entry3) / sizeof(*entry3));																//places data into array
	bubblesortaddress(entry3, sizeof(entry3) / sizeof(*entry3));															//sort by department using address arithmetic
	fprintf(outFile, "----------------“B” option sorted results done by address arithmetic sort:----------------\n");
	for (int i = 0; i < 28; i++)																							//prints sorted data by pointer entry3
 		{
     	   fprintf(outFile,"%s, %s, %s, %0.2f, %s.\n", entry3[i].surname, entry3[i].givenname, entry3[i].department, entry3[i].payrate, entry3[i].eyecolor);
   		}


	fclose(outFile);
	fclose(inFile);
	return 0;
}



