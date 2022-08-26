#include "proj.h"
void timer()
{
	int s=10, count;
	char c;
	while(1)
	{
		printf("  Your session begins in %d seconds\r ", s);
		Sleep(1000);
		s--;
		if (s == 0)
		{
			break;
		}

	}		
}	