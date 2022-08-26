#include "proj.h"

float find_highest(char username [])
{
    FILE* fp = fopen("accuracy.csv", "r");
    float records[200];
    int count = 0;
    char buff[200];
    while(fgets(buff, 200, fp))
    {
        char* val = strtok(buff, ",");
        if (!(strcmp(val, username)))
        {
            for(int i = 0;(val!=NULL);i++)
            {
                val = strtok(NULL, ",");  
                sscanf(val, "%f", (records+i));
                count++; 
            }
        }
    }
    fclose(fp);
    float ele = records[0];
    for(int i = 0;i<count;i++)
    {
        if (records[i] > ele)
        {
            ele = records[i];
        }
    }
    return ele;
}
float find_fastest(char username[])
{
    FILE* fp = fopen("Typing_test.csv", "r");
    char buff[100];
    float records[100];
    int count = 0;
    while(fgets(buff, 100, fp))
    {
        char* val = strtok(buff, ",");
        if(!(strcmp(val, username)))
        {
            for(int i = 0;(val!=NULL);i++)
            {
                val = strtok(NULL, ",");
                sscanf(val, "%f", records+i);
                count++;
            }
            break;
        }
    }
    fclose(fp);
    float ele = records[0];
    for(int i = 0;i<count;i++)
    {
        if (ele < records[i])
        {
            ele = records[i];
        }
    }
    return ele;
}
int menu(int index)
{
    system("cls");
    char choice;
    FILE* fp1;
    fp1 = fopen("users.dat", "r");
    user r_usernames[100];
    FILE* fp2;
    fp2 = fopen("count.dat", "r");
    int count;
    fread(&count, sizeof(int), 1, fp2);
    fread(r_usernames, sizeof(user), count, fp1);
    fclose(fp1); fclose(fp2);
    printf("\033[0;33m");
    printf("Welcome %s!\n", r_usernames[index].username);
    printf("\n\n");
    float menu_display_accuracy = find_highest(r_usernames[index].username);
    float menu_typing_test  = find_fastest(r_usernames[index].username);
    fwrite(r_usernames, sizeof(user), count, fp1);
    printf("\t\t\t\t\t\t\t\t\t Your records : \n");
    printf("\t\t\t\t\t\t\t\t\t Your Highest Accuracy recorded is %.1f%s \n", menu_display_accuracy, "%");
    printf("\t\t\t\t\t\t\t\t\t Your Fastest Typing Speed recorded is %.1f words per second\n", menu_typing_test/4.7);
    printf("\n");
    printf("Enter choice \n");
    printf("\033[0;36m");
    printf("1.Start New Session\n2.View My Records\n3.Main Menu\n\n");
    printf("\033[0;32m");
    int n;
    char c = getch();
    char n1[2];
    n1[0] = c;
    n = atoi(n1);
    printf("\033[0m");
    switch(n)
    {
        case 1: return 1;
                break;
        case 2: view_my_records(r_usernames[index].username);
                menu(index);
                break;
        case 3: main();
                break;
        default : system("cls");
                  main();
                  break;
    }
}