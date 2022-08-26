#include "proj.h"

void store(float data, int index, char file_name[])
{
    FILE* fp1 = fopen(file_name, "r");
    FILE* fp2 = fopen("count.dat", "r");
    int count;
    fread(&count, sizeof(int), 1, fp2);
    lines user_records[count];
    char buffer[1000];
    int i = 0;
    for(int i = 0;(fscanf(fp1, "%s", buffer)==1);i++)
    {
        strcpy(user_records[i].user_lines, buffer);
    }
    fclose(fp1);
    FILE* fp3 = fopen(file_name, "w");
    char add[20];
    sprintf(add, "%f,", data);
    add[strlen(add)] = '\0';
    int len = strlen(user_records[index].user_lines);
    for(int i = 0;i<(strlen(add)+1);i++)
    {
        user_records[index].user_lines[len+i] = add[i];
    }
    for(int i = 0;i<count;i++)
    {
       fprintf(fp3, "%s\n", user_records[i].user_lines);
    }
    fclose(fp3);fclose(fp2);
}
