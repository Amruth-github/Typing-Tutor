#include "proj.h"

int read_user_details()
{
    user r_usernames[100];
    FILE* fp1;
    FILE* fp2;
    int count;
    fp1 = fopen("users.dat", "r");
    fp2 = fopen("count.dat", "r");
    fread(&count, sizeof(int), 1, fp2);
    fread(r_usernames, sizeof(user), count, fp1);
    fclose(fp1);fclose(fp2);
    printf("\033[0;33m");
    printf("Enter your username: ");
    char u[20];
    fflush(stdin);
    printf("\033[0;32m");
    gets(u);
    while(!(strcmp(u,"")))
    {
        printf("\033[0;31m");
        printf("Blank spaces are not allowed\n");
        printf("\033[0;32m");
        printf("Enter proper username : ");
        fflush(stdin);
        gets(u);
    }
    int a = check_username(r_usernames, u, count);
    while (!a)
    {
        printf("\033[0;31m");
        printf("Username not found! \n");
        printf("\033[0;33m");
        printf("Please Enter the right username:  ");
        while(!(strcmp(u,"")))
        {
            printf("\033[0;31m");
            printf("Blank spaces are not allowed\n");
            printf("\033[0;33m");
            printf("Enter proper username : ");
            fflush(stdin);
            gets(u);
        }
        fflush(stdin);
        printf("\033[0;32m");
        gets(u);
        a = check_username(r_usernames, u, count);
    }
    int index = check_index(r_usernames,u,count);
    return index;
}
int read_new_user_details()
{
    int count;
    user r_username[100];
    char u[20];
    printf("\033[0;33m");
    printf("Enter a new username : ");
    fflush(stdin);
    printf("\033[0;32m");
    FILE* fp5 = fopen("Typing_test.csv", "a+");
    gets(u);
    while(!(strcmp(u,"")))
    {
        printf("\033[0;31m");
        printf("Blank spaces are not allowed\n");
        printf("\033[0;33m");
        printf("Enter proper username : ");
        printf("\033[0;32m");
        fflush(stdin);
        gets(u);
    }
    FILE* fp1;
    FILE* fp2;
    fp1 = fopen("users.dat", "r");
    fp2 = fopen("count.dat", "r");
    fread(&count, sizeof(int), 1, fp2);
    fread(r_username, sizeof(user), count, fp1);
    int a = check_username(r_username, u, count);
    while (a)
    {
        printf("\033[0;31m");
        printf("User name already taken!\n");
        printf("\033[0;33m");
	    printf("Try another username: ");
        fflush(stdin);
        printf("\033[0;32m");
        gets(u);
        while(!(strcmp(u,"")))
        {
            printf("\033[0;31m");
            printf("Blank spaces are not allowed\n");
            printf("\033[0;33m");
            printf("Enter proper username : ");
            printf("\033[0;32m");
            fflush(stdin);
            gets(u);
        }
        a = check_username(r_username,u,count);
        printf("\033[0m");
    }
    FILE* fp6 = fopen("accuracy.csv", "a+");
    int index = check_index(r_username,u,count);
    strcpy(r_username[count].username, u);
    count++;
    fclose(fp1);fclose(fp2);
    FILE* fp3;
    FILE* fp4;
    fp3 = fopen("users.dat", "w");
    fp4 = fopen("count.dat", "w");
    fwrite(r_username, sizeof(user), count, fp3);
    fwrite(&count, sizeof(int), 1, fp4);
    fprintf(fp5,"%s,\n", u);
    fprintf(fp6, "%s,\n", u);
    fclose(fp3);fclose(fp4);fclose(fp5);fclose(fp6);
    return index;
}