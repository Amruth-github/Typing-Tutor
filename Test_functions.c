#include "proj.h"

float do_test(int file_choice)
{
	time_t end, start, end_time;
	int count=0, j=0;
	int level_choice;
	printf("\033[0;33m");
	printf("\nEnter difficulty level : \n\n");
	printf("\033[0;36m");
	printf("1.EASY(1 minute and 30 seconds)\n2.MEDIUM (1 minute)\n3.HARD(45 seconds)\n");
	printf("\033[0;32m");
	char c3[2];
	c3[0]= getch();
	level_choice = atoi(c3);
	printf("\033[0;33m");
	display_script(file_choice);
	printf("\n");
	switch(level_choice)
	{
		case 1: end_time=117391;
				break;
		case 2: end_time = 78261;
				break;
		case 3: end_time = 60000;
				break;
		default:printf("\033[0;31m");
				printf("Enter a valid choice\n");
				printf("\033[0m");
				break;
	}
	timer();
	printf("\033[0;33m");
	printf("Your session has begun\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("\033[0;32m");
	start = time(NULL);
	FILE* fp = fopen("output.txt", "wb");
	for(int z = 0;((j<5) && (clock() < end_time));z++)
	{
		char c = getc(stdin);
		fputc(c, fp);
		count+=1;
		if (c == '\n')
		{
			j+=1;
		}
	}
	printf("\033[0m");
	end = time(NULL);
	printf("\033[0;33m");
	float typing_speed = (count/difftime(end,start));
	printf("Your Typing Speed was %.1f words per second during this session\n", typing_speed/4.7);
	getch();
	fclose(fp);
	return typing_speed;
}