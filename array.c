#include <stdio.h>

/* 
 * Name : <Hoyoung Jung>
 * Program to experiment with arrays
 */
 
 #define NumMovies 10
 #define MaxGrosses 5
 
int main()
{
/* The declaration of arrays and variables */
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    double sum;
    int i;
    int highestGrossIndex = 0;
    double highestGross = 0;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    int j;
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", 
                         "Just Go With It", "Gnomeo and Juliet", "Drive Angry", 
                         "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son", 
                         "True Grit"};
                         
/* This loop displays the movie titles and their gross */
    for(i=0;  i<NumMovies; i++)
    {
        printf("Movie %d 	%30.30s: %.0f\n", i+1, names[i], gross[i]);
    }

/* This loop finds the total gross of all the movies */
    sum = 0;        /* Initialize to zero */
    for(i = 0;  i<NumMovies;  i++)
    {
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f \n", sum);
    
/* This loop determines the highest grossing film and outputs the name */
    highestGross = 0;
    for(i=0;  i<NumMovies;  i++)
    {
        if(gross[i] > highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);
    
/* These series of loops finds the films with the highest gross within a certain value */    
    highestGross=0;
	for(i=0; i<MaxGrosses; i++)
	{
		for(j=0; j<NumMovies; j++)
		{
				if((gross[j]<=maxGross[i]) & (gross[j]>highestGross))
				{
					highestGrossIndex = j;
					highestGross = gross[highestGrossIndex];
				}
		}
		if(highestGross==0)
			printf("No film made less than %.0f\n", maxGross[i]);
		else
			printf("The highest gross less than %.0f is %s at %.0f\n", maxGross[i], names[highestGrossIndex], highestGross);

	}
}