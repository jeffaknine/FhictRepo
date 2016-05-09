#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]) {
	if (strcmp(argv[0],"morning")==0)
	{
		printf("Good Morning\n");
	}
	else if (strcmp(argv[0],"evening")==0)
	{
		printf("Good evening\n");
	}
	return 0;
}