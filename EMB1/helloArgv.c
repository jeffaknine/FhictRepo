#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int opt = 0;
	char *mor = NULL; 
	char *eve = NULL;
	
	while((opt = getopt(argc, argv, "hm:e:")) != -1) {
		switch(opt) {
			case 'h':
				printf("n\nOptions:\n1. [-m] [value] -> Prints 'Good Morning World!'. [value] indicates amount of repeats\n2. [-e] [value] -> Prints 'Good Evening World!'. [value] indicates amount of repeats\n3. [-h] -> Display help\n\n");
				break;
			case 'm':
				mor = optarg;
				int count_m = *mor - '0';
				int i;
				for (i = 0; i < count_m; i++)
				{
					printf("\n[%d] Good Morning world!", i+1);
				}
				printf("\n");
				break;
			case 'e':
				eve = optarg;
				int count_e = *eve - '0';
				int k;
				for (k = 0; k < count_e; k++)
				{
					printf("\n[%d]Good Evening world!", k+1);
				}
				printf("\n");
				break;
			case '?':
				if (optopt == 'm') {
					printf("\n[1] Good Morning world!\n");
				}
				else if (optopt == 'e') {
					printf("\n[1] Good Evening world!\n");
				} 
				else {
					printf("\nInvalid option");
				}
				break;			
		}
	}
	printf("\n");
	return 0;
}
