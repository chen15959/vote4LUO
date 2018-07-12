// votetop30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	if (argc == 4)
	{
		FILE * fp = fopen(argv[1], "r");
		if (fp)
		{
			char * buffer = (char *)malloc(1048576 * sizeof(char));
			fread(buffer, 1, 1048576, fp);
			fclose(fp);

			char * input = strstr(buffer, "<input");
			if (input == NULL)
			{
				printf("the format of the page is changed.\n");
				free(buffer);
				return 2;
			}
			
			char * name = strstr(input, "name=\"");
			if (name == NULL)
			{
				printf("the format of the page is changed.\n");
				free(buffer);
				return 3;
			}
			char * name_end = strstr(name + 6, "\"");
			if (name_end == NULL)
			{
				printf("the format of the page is changed.\n");
				free(buffer);
				return 4;
			}

			char * value = strstr(input, "value=\"");
			if (value == NULL)
			{
				printf("the format of the page is changed.\n");
				free(buffer);
				return 5;
			}
			char * value_end = strstr(value + 7, "\"");
			if (value_end == NULL)
			{
				printf("the format of the page is changed.\n");
				free(buffer);
				return 6;
			}


			char * k = name + 6;
			char * v = value + 7;

			*name_end = '\0';
			*value_end = '\0';

			FILE * output = fopen(argv[2], "w");
			fprintf(output, "id=%s&%s=%s", argv[3], k, v);
			fclose(output);

			free(buffer);
		}
		else
		{
			printf("can not open file [%s]\n", argv[1]);
			return 1;
		}
	}
	else
	{
		printf("Usage: votetop30.exe votetop30.html post.txt 20\n");
	}

	return 0;
}

