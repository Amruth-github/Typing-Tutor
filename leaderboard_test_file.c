#include "proj.h"

void point(lead scores[], lead *p[], int count)
{
	for (int i = 0; i < count; i++)
	{
		p[i] = scores + i;
	}
}
void sort(lead *p[], int count) // Selection Sort
{
	for (int i = 0; i < count; i++)
	{
		int pos = i;
		for (int j = i + 1; j < count; j++)
		{
			if (p[j]->score > p[pos]->score)
			{
				pos = j;
			}
		}
		if (pos != i)
		{
			lead *temp = p[pos];
			p[pos] = p[i];
			p[i] = temp;
		}
	}
}
void display_leaderboard(lead *p[], int count)
{
	printf("\033[0;33m");
	printf("\t\tName\t|\tScores\n");
	for (int i = 0; i < count; i++)
	{
		printf("\t%d\t%s\t|\t%.1f\n", i + 1, p[i]->name, p[i]->score);
	}
	printf("\033[0m");
}
void leaderboard(char file_name[])
{
	FILE *fp = fopen("count.dat", "r");
	int count;
	fread(&count, sizeof(int), 1, fp);
	lead scores[count];
	FILE *fp1 = fopen(file_name, "r");
	char buff[200];
	for (int i = 0; fgets(buff, 200, fp1); i++)
	{
		char *val = strtok(buff, ",");
		strcpy(scores[i].name, val);
		val = strtok(NULL, ",");
		float tot = 0;
		int n = 0;
		while (val != NULL)
		{
			float num;
			sscanf(val, "%f", &num);
			tot += num;
			n++;
			val = strtok(NULL, ",");
		}
		scores[i].score = tot / n;
	}
	lead *pointer_array[count];
	point(scores, pointer_array, count);
	sort(pointer_array, count);
	display_leaderboard(pointer_array, count);
	fclose(fp);
	fclose(fp1);
}