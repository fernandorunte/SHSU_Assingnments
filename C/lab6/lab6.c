#include <unistd.h>  	//create pipe
#include <stdio.h>
#include <string.h>
#include <wait.h>  		//process synchronization
#include <time.h>  		// clock
#include <stdlib.h>
#include "randapi.h"



#define MaxLen 128
#define PipeStdIn 0    //stdin for Unix is  0
#define PipeStdOut 1   //stdout for Unix is 1
#define sleeptime 5




int main (void) {
   pid_t pid, pid2;
   int status;
   int myPipes[2];
   char buff[MaxLen + 1];
   char message[MaxLen+1];
   char message2[MaxLen+1];
   char bufff[MaxLen+1];
   int timedifference;
   time_t begintime;


	seedRandGenerator();


	pipe(myPipes);
    pid = fork();
	pid2 = fork();

    if (pid2 == 0)
    {									 //pipes created

        int status2;

        if (pid == 0)
        	{ 											//child 2  life support
        		begintime = time(NULL);
            	close(myPipes[PipeStdIn]);
				sleep(getRandFloat(6.0));					//0 to 6 seconds uniformaly distributed
				strcpy(message2, "Environment adjusted.");
				timedifference = difftime(time(NULL), begintime);
				snprintf(bufff, 60, "\nProcessing time elapsed: %d seconds.\n", timedifference);
				strcat(message2, bufff);
				write( myPipes[PipeStdOut], message2, strlen(message2) + 1 );
        	}
        else
        	{																//navigation child child 1
				begintime = time(NULL);
				close(myPipes[PipeStdIn]);
		 		sleep(getRandExponential(sleeptime));						//exponentially distributed with a mean of 5
		 		strcpy(message, "Air levels have adjusted.");
		 		timedifference = difftime(time(NULL), begintime);
		 		snprintf(bufff, 60, "\nProcessing time elapsed: %d seconds.\n", timedifference);
		 		strcat(message, bufff);
		 		write( myPipes[PipeStdOut], message, strlen(message) + 1 );
		 		sleep(getRandExponential(sleeptime-1)); 					//time for environment adjustment
        		wait(&status2);
       	 }
    }
    else
    	{																	//parent process

			close(myPipes[PipeStdOut]);
			read( myPipes[PipeStdIn], buff, MaxLen);  					//blocking read (suspend)
	 		printf("Recieved data: %s\n", buff);    					// ret =  number char read
	 		begintime = time(NULL);
	 		snprintf(bufff, MaxLen, "%s\n", ctime(&begintime));
	 		printf("%s\n", bufff);
			wait(&status);
    }
    close(myPipes[PipeStdIn]);
 	close(myPipes[PipeStdOut]);
    return 0;
}