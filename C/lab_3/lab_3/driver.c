#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include "mymathlib.h"

int main()
{

	char fileOutName[25];
	int numbersToSum = 0;
	float angle = 0.0;
	float sumofFloated = 0.0;
	float height = 0.0;
	float volume = 0.0;
	float surface = 0.0;
	float radius = 0.0;
	int choice = 0;
	double answer2 = 0.0;


	FILE *outFile; 								//logical output file in program
	outFile=fopen("lab3_results.txt","a");		//open file for writting




	printf("Hello! Please select process: Enter 1 for sphere, 2 for volCynlinder, 3 for sumFloats, and 4 for sin.\n");
	scanf("%d", &choice);




	switch(choice)
		{
			case 1:
				{
					printf("Sphere selected. Enter radius value in cm:\n");
					scanf("%f", &radius);
					sphere(radius, &surface, &volume);
					printf("Sphere given radius: %f. Surface area calculated: %f. volume calculated: %f. \n", radius, surface, volume);
					fprintf(outFile, "Sphere given radius: %f. Surface area calculated: %f. volume calculated: %f. \n", radius, surface, volume);
				}
			break;

			case 2:
				{
					printf("volCylinder selected. Enter value radius value in feet:\n");
					scanf("%f", &radius);
					printf("Enter height value:\n");
					scanf("%f", &height);
					volume = volCylinder(radius, height);
					printf("Cylinder given radius: %f. Height given: %f. Volume calculated: %f.\n", radius, height, volume);
					fprintf(outFile, "Cylinder given radius: %f. Height calculated: %f. Volume calculated: %f.\n", radius, height, volume);
			}
			break;

			case 3:
				{
					printf("How many floating numbers to be summed?\n");
					scanf("%d", &numbersToSum);
					//float *arrayofNumbertoSum = malloc(numbersToSum*sizeof(float));
					float arrayofNumbertoSum[numbersToSum];

					for (int x = 0; x < numbersToSum; x++)					//loops for the float number inputs
						{
							printf("What is the float?\n");
							scanf("%f", &arrayofNumbertoSum[x]);

						}
					fprintf(outFile,"Printing unsorted raw data of array: ");
					for(int x = 0; x < numbersToSum; x++)
						{
							fprintf(outFile, "%0.8f, ", arrayofNumbertoSum[x]);			//print unsorted raw data to outFile

						}
					fprintf(outFile,"Done!\n");


					printf("Printing unsorted raw data of array: ");
									for(int x = 0; x < numbersToSum; x++)
										{
											printf("%0.8f, ", arrayofNumbertoSum[x]);			//print unsorted raw data to screen

										}
					printf("Done!\n");



					for (int y = 0; y < numbersToSum - 1; y++)					//loop begins for sorting by selection
						{
							for (int z = y + 1; z < numbersToSum; z++)
								{
									if (arrayofNumbertoSum[y] > arrayofNumbertoSum[z])		//condition for creating ascending order
										{
											float temp = arrayofNumbertoSum[y];
											arrayofNumbertoSum[y] = arrayofNumbertoSum[z];
											arrayofNumbertoSum[z] = temp;
										}
								}
						}


					printf("Printing sorted data of array: ");

						for(int x = 0; x < numbersToSum; x++)
							{
								printf("%0.8f, ", arrayofNumbertoSum[x]);			//print sorted data to screen

							}

					printf("Done!\n");


					fprintf(outFile,"Printing sorted data of array: ");

						for(int x = 0; x < numbersToSum; x++)
							{
								fprintf(outFile,"%0.8f, ", arrayofNumbertoSum[x]);			//print sorted data to outFile

							}

					fprintf(outFile,"Done!\n");

					sumofFloated = sumFloats(arrayofNumbertoSum, numbersToSum);
					printf("Sum of given floats: %0.8f. \n", sumofFloated);
					fprintf(outFile, "Sum of given floats: %0.8f. \n", sumofFloated);
				}
			break;


			case 4:
			{
				printf("Enter angel: \n");
				scanf("%f", &angle);
				float radians = (angle*0.0174532925);					//converts given degree into radians
				answer2 = sine(radians);
				printf("Given angle: %f, sin value: %f. \n", angle, answer2);
				fprintf(outFile, "Given angle: %f, sin value: %f. \n", angle, answer2);
			}
			break;


			default:
			printf("Pogram terminating.");
			break;









		}					//end switch



fclose(outFile);
return 0;

}