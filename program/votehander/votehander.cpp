// votehander.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define SUCCEED_STR "{\"ret\":1,\""
#define REFUSED_STR "{\"ret\":-1,"

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		char buffer[256];
		FILE * fp = fopen(argv[1], "r");
		if (fp)
		{
			int len = sizeof(SUCCEED_STR) - 1;
			fread(buffer, 1, len, fp);
			fclose(fp);

			if (memcmp(buffer, SUCCEED_STR, len) == 0)
			{
				FILE * output = fopen(argv[2], "w");
				if (output)
				{
					fprintf(output, "vote_succeed=1");
					fclose(output);
					return 0;
				}
			}
			else if (memcmp(buffer, REFUSED_STR, len) == 0)
			{
				FILE * output = fopen(argv[2], "w");
				if (output)
				{
					fprintf(output, "vote_refused=1");
					fclose(output);
					return 0;
				}
			}
		}

		return 1;
	}
	else
	{
		printf("Usage votehander.exe votehander.json votehander.result\n");
		return 0;
	}
}

