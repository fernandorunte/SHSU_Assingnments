#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gross.h"
#include "fica.h"


//float calculateGross(float hours, float payrate);
//float calculateFica(float ytd, float gross);



/*
void newPage(FILE *outFile, float Pgross, float Pfica, float Pnet)
{
	fprintf(outFile,"Page Totals:%*.2f %*.2f %*.2f",Pgross, Pfica, Pnet);	//could not implement the newPage
}
*/


int main()
{

		FILE *inFile;		//logical input file name in program
		FILE *outFile;		//handle to the output file

		char fileInName[21];	//actual input path and file name
		char fileOutName[21];	//actual output path and file name
		char response;


		printf("Enter the name of the input text file \n");
		scanf("%s", fileInName);
		inFile=fopen(fileInName, "r");

		if(inFile==NULL)
		{
			printf("Input file does not exist. Program will now terminate.\n");	//check for existence of file
			exit(1);
		}

		printf("Enter desired name of file to hold the report.\n");
		scanf("%s", fileOutName);

		if((outFile=fopen(fileOutName, "r"))!=NULL)
		{
			printf("A file by the name %s already exists. \n", fileOutName);	//preventing overiding
			printf("Do you wish to overide?(Y or N):\n");
			scanf("%*c%c", &response);

			if((response=='n')||(response=='N'))
			{
				fclose(outFile);
				printf("Program aborted to prevent overwrite.\n");
				exit(1);
			}
		}

		outFile=fopen(fileOutName, "w");
		if(outFile==NULL)
		{
			printf("Could not create the output file. Program terminating.\n");
			exit(1);

		}

		//now we initialize variables and obtain info to calculate
		char givenName[10];	//first name
		char surName[10];	//last name
		char department[10]; 	//department name, also the key
		float hoursWkd, payrate, gross, yearToDate;
		float overtime=40;
		int linekt=0;		//line counter
		int pagekt=0;		//page counter
		int max_width_names=18;
		int max_width_numbers=15;
		int empNo;
		float taxRate=0.71;
		float Pgross, Pfica, Pnet, Rgross, Rfica, Rnet=0.0;


		while((fscanf(inFile, "%d%s%s%s%f%f%f",&empNo, givenName, surName, department, &yearToDate, &payrate, &hoursWkd ))!=EOF)
		{


			if(linekt==0||linekt==5)
			{
				pagekt=pagekt+1;
				fprintf(outFile,"\f\n\n\t\t\tACME Tools\t\t\tPage %d\n\n\n", pagekt);
				//prints alinging the header
				fprintf(outFile,"%*s\t",max_width_numbers,"Emp. No.");
				fprintf(outFile,"%*s\t",max_width_numbers,"Name");
				fprintf(outFile,"%*s\t",max_width_numbers,"     ");
				fprintf(outFile,"%*s\t",max_width_numbers,"Dept.");
				fprintf(outFile,"%*s\t",max_width_numbers,"New YTD");
				fprintf(outFile,"%*s\t",max_width_numbers,"Gross");
				fprintf(outFile,"%*s\t",max_width_numbers,"FICA");
				fprintf(outFile,"%*s \n\n",max_width_numbers,"Net");
				linekt=0;

			}


		linekt=linekt+1;							//increment line counter

		


											//print to file right justified
		fprintf(outFile,"%*d",max_width_numbers,empNo);
		fprintf(outFile,"%*s",max_width_names,givenName);
		fprintf(outFile,"%*s",max_width_names,surName);
		fprintf(outFile,"%*s",max_width_names,department);
		fprintf(outFile,"%*.2f",max_width_numbers,yearToDate);
		fprintf(outFile,"%*.2f",max_width_numbers,calculateGross(hoursWkd,payrate));
		gross=calculateGross(hoursWkd,payrate);
		fprintf(outFile,"%*.2f",max_width_numbers,(calculateFica(yearToDate, gross)));
		fica=calculateFica(yearToDate, gross);
		fprintf(outFile,"%*.2f\n",max_width_numbers,(gross-fica));

					
		Pgross=Pgross + gross;
		Pfica=Pfica+fica;		//sums up Pgross, Pfica, Pnet
		Pnet=(Pgross-Pfica)+Pnet;




		}



		
		fprintf(outFile,"%*s",max_width_names,"Running Totals:");
		fprintf(outFile,"\t%*.2f",max_width_numbers,Pgross);
		fprintf(outFile,"\t%*.2f",max_width_numbers,Pfica);			//print runnign totals
		fprintf(outFile,"\t%*.2f",max_width_numbers,Pnet);



		fclose(inFile);			//close files 
		fclose(outFile);
		return 0;
}

/*
float gross;

float calculateGross(float hours, float payrate)
{
	gross=(hours>40)?(((hours-40.0)*1.5*payrate)+40.0*payrate):(hours*payrate);
	return gross;

}


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





*/