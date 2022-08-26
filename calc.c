#include "proj.h"

float calc_accuracy(int script_num)
{
	FILE* fp = fopen("output.txt", "r");
	FILE* fp1;
	switch(script_num)
	{
		case 1: fp1 = fopen("script_1.txt", "r");
				break;
		case 2:	fp1 = fopen("script_2.txt", "r");
				break;
		case 3: fp1 = fopen("script_3.txt", "r");
				break;
	}
	float chars = 0;
	float num_of_chars = 0;
	while(True)
	{
		char c1 = fgetc(fp);
		char c2 = fgetc(fp1);
		if (c1 == EOF || c2 == EOF)
		{
			break;
		}
		if (c1 == c2)
		{
			chars++;
		}
	}
	char buff[100];
	fseek(fp1, 0, SEEK_SET);
	while(fgets(buff, 100, fp1))
	{
		num_of_chars+=strlen(buff);
	}
	printf("Your accuracy during this session is %.1f \n", (chars/num_of_chars)*100);
	getch();
	fclose(fp);fclose(fp1);
	system("del output.txt");
	return (chars/num_of_chars)*100;
}