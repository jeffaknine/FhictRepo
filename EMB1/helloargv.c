#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char const *argv[])
{
	int opt = 0;
	char *morn_fname = NULL;
	char *even_fname = NULL;

	
	while((opt = getopt(argc, argv ,"me,help"))!= - 1)
	{
		switch(opt)
		{
			case 'm':
			morn_fname = optarg;
			int count1 = *morn_fname - '0';
			for (int i = 0; i < count1; ++i)
			{
				printf("\nGood Morning");
			}
			break;

			case 'e':
			even_fname = optarg;
			int count = *even_fname - '0';
			for (int i = 0; i < count; ++i)
			{
				printf("\nGood Evening");
			}
			break;

			case '?':
		    /* Case when user enters the command as
		     * $ ./cmd_exe -i
		     */
		    if (optopt == 'e') 
		    {
		    	printf("\nMissing mandatory Evening option");
		    /* Case when user enters the command as
		     * # ./cmd_exe -o
		     */
			}
			else if (optopt == 'm') 
			{
		    	printf("\nMissing mandatory Morning option");
		  	} 
		  	else if (optopt == 'help')
		  	{
		  		printf("\nMissing mandatory Morning option");
		  	}
		  	else
		  	{
		  		printf("\nInvalid option received");
		  	}
	  		break;

	  		case 'help':
	  		printf("\nThis is really helping...");
	  		break;
	  	}
	}

	printf("\n");
	return 0;
}