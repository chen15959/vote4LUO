// votetop30status.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		char * buffer = (char *)malloc(1048576);
		FILE * fp = fopen(argv[1], "r");
		if (fp)
		{
			fread(buffer, 1, 1000000, fp);
			fclose(fp);


			vector<pair<char *, char *>> status;

			char * div_begin = buffer;
			do
			{
				div_begin = strstr(div_begin + 1, "<div class=\"x_snd_thirty_vote_num\">");
				if (div_begin)
				{
					char * div_end = strstr(div_begin, "</div>");
					if (div_end)
					{
						char * ticket_begin = strstr(div_begin, "<em>");
						if (ticket_begin && ticket_begin < div_end)
						{
							char * ticket_end = strstr(ticket_begin, "</em>");
							if (ticket_end && ticket_end < div_end)
							{
								char * id_begin = strstr(ticket_end, "<a class=\"voted\" onclick=\"doVote(");
								if (id_begin && id_begin < div_end)
								{
									char * id_end = strstr(id_begin, ");\">");
									if (id_end && id_end < div_end)
									{
										char * ticket = ticket_begin + 4;
										*ticket_end = '\0';
										char * id = id_begin + 33;
										*id_end = '\0';

										status.push_back(pair<char *, char *>(id, ticket));
									}
								}
							}
						}
						div_begin = div_end;
					}
				}
			}
			while (div_begin);


//			for (vector<pair<char *, char *> >::const_iterator it = status.begin(); it != status.end(); ++it)
//			{
//				printf("g%s=%s\n", it->first, it->second);
//			}

			if (status.size() == 30)
			{
				FILE * output = fopen(argv[2], "w");
				if (output)
				{
					for (vector<pair<char *, char *> >::const_iterator it = status.begin(); it != status.end(); ++it)
					{
						fprintf(output, "g%s=%s&", it->first, it->second);
					}
					fprintf(output, "dummy=1");

					fclose(output);
				}
			}

			free(buffer);
		}
	}
	else
	{
		printf("Usage: votetop30status.exe votetop30.html post.txt\n");
	}

	return 0;
}

