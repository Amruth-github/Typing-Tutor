#include "proj.h"

void display_script(int file_choice)
{
    FILE* fp1;
	switch(file_choice)
	{
		case 1: fp1 = fopen("script_1.txt", "rb");
				break;
		case 2: fp1 = fopen("script_2.txt", "rb");
				break;
		case 3: fp1 = fopen("script_3.txt", "rb");
				break;
	}
	char buff[100];
	while(fgets(buff, 100, fp1))
	{
		fputs(buff, stdout);
		fputc('\n', stdout);
	}
}

void view_my_records(char username[])
{
	FILE* fp = fopen("Typing_test.csv", "r");
	FILE* fp1 = fopen("accuracy.csv", "r");
	char buff[100];
	int count = 0;
	float records_speed[100];
	float records_accuracy[100];
	while(fgets(buff, 100, fp))
	{
		char* val = strtok(buff, ",");
		if (!(strcmp(username, buff)))
		{
			for(int i = 0;val;i++)
			{
				val = strtok(NULL, ",");
				sscanf(val, "%f", records_speed+i);
				count++;
			}
			break;
		}
	}
	while(fgets(buff, 100, fp1))
	{
		char* val = strtok(buff, ",");
		if (!(strcmp(username, buff)))
		{
			for(int i = 0;val;i++)
			{
				val = strtok(NULL, ",");
				sscanf(val, "%f", records_accuracy+i);
			}
			break;
		}
	}
	fclose(fp);fclose(fp1);
	printf("\033[0;33m");
	printf("Sl.no\t|Speed               \t|Accuracy\n");
	for(int i = 0;i<count-2;i++)
	{
		printf("%d\t|%.1f words per second\t|%.1f%s\n", i+1, records_speed[i]/4.7, records_accuracy[i], "%");
	}
	printf("Enter any key to return to menu\n");
	printf("\033[0;m");
	getch();
}

