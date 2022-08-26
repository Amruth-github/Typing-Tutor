#include "proj.h"

void main()
{
	int number_of_users, index,choice_1, session_choice;
	float typing_speed, accuracy;
	system("cls");
	FILE* fp1;
	FILE* fp2;
	FILE* fp5 = fopen("script_1.txt", "r");
	FILE* fp6 = fopen("script_2.txt", "r");
	FILE* fp7 = fopen("script_3.txt", "r");
	FILE* fp8  =fopen("Typing_test.csv", "r");
	FILE* fp9 = fopen("accuracy.csv", "r");
	fp1 = fopen("users.dat", "r");
	fp2 = fopen("count.dat", "r");
	if (fp1 == NULL)
	{
		FILE* fp3;
		fp3 = fopen("users.dat", "w");
		fclose(fp3);
	}
	if(fp2 == NULL)
	{
		FILE* fp4;
		fp4 = fopen("count.dat", "w");
		int count = 0;
		fwrite(&count, sizeof(int), 1, fp4);
		fclose(fp4);
	}
	if (fp5 == NULL)
	{
		script_write();
		fclose(fp5);
	}
	if (fp6 == NULL)
	{
		script_write_1();
	}
	if (fp7 == NULL)
	{
		script_write_2();
	}
	if (fp8 == NULL)
	{
		FILE* fp10 = fopen("Typing_test.csv", "w");
		fclose(fp10);
	}
	if (fp9 == NULL)
	{
		FILE* fp11  = fopen("accuracy.csv", "w");
		fclose(fp11);
	}
	fread(&number_of_users, sizeof(int), 1, fp2);
	fclose(fp1);fclose(fp2);fclose(fp5);fclose(fp6);fclose(fp7);
	char choice;
	printf("\033[0;33m");
	printf("\t\t\t\t\t\t\t\t\tWELCOME TO TYPING TUTOR\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Active Users: %d  \n\n", number_of_users);
	printf("\033[0m");
	printf("\033[0;36m");
	printf("Are you a new user?\n");
	printf("1.YES, I'm a New User\n");
	printf("2.I'm an existing User\n");
	printf("3.Display Leaderboard\n");
	printf("4.Exit\n");
	printf("Enter your choice\n");
	printf("\033[0m");
	int menu_choice;
	printf("\033[0;32m");
	char n1[2];
	int script_choice = generate_random();
	n1[0] = getch();
	menu_choice = atoi(n1);
	printf("\033[0m");
	printf("\n\n");
	switch (menu_choice)
	{
		case 1: index = read_new_user_details();
				if(menu(index))
				{
					typing_speed = do_test(script_choice);
					accuracy = calc_accuracy(script_choice);
					store(typing_speed, index, "Typing_test.csv");
					store(accuracy, index, "accuracy.csv");
					menu(index);
				}
				break;
		case 2: index = read_user_details();
				if(menu(index))
				{
					typing_speed = do_test(script_choice);
					accuracy = calc_accuracy(script_choice);
					store(typing_speed, index, "Typing_test.csv");
					store(accuracy, index, "accuracy.csv");
					menu(index);
				}
				break;
		case 3: system("cls");
				printf("\033[1;33m");
				printf("Enter the leaderboard you wish to view : \n");
				printf("1.Typing Speed \n");
				printf("2.Accuracy\n");
				int n;
				char n3[2];
				n3[0] = getch();
				n = atoi(n3);
				printf("\033[0m");
				switch(n)
				{
					case 1: printf("\033[1;33m");
							printf("\nSpeed Leaders\n\n");
							printf("\033[1;0m");
							leaderboard("Typing_test.csv");
							break;
					case 2: printf("\033[1;33m");
							printf("Accuracy Leaders\n\n");
							printf("\033[1;0m");
							leaderboard("accuracy.csv");
							break;
					default:system("cls");
							printf("Enter a valid option");
							main();
							break;
				}
				printf("\033[0;36m");
				printf("Press any number to go back to main menu\n");
				printf("Press 0 to exit\n");
				char n2[2];
				printf("\033[0;32m");
				n2[0] = getch();
				int n1 = atoi(n2);
				if (n1)
				{
					main();
				}
				else
				{
					exit(0);
				}
				break;
		case 4: exit(0);
				break;
		default:system("cls");
				printf("Please Enter a valid option!\n");
				fflush(stdin);
				main();
			    break;
	}
	
}
	