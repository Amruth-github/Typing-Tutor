#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#define True 1
#define False 0
int read_user_details();
int read_new_user_details();
typedef struct user
{
    char username[50];
}user;
int check_username(user [], char [], int);
int menu(int);
int check_index(user [],   char [],  int);
typedef struct leaderboard
{
	char name[20];
	float score;
}lead;
void display_script(int);
float do_test(int);
float calc_accuracy(int);
void timer();
void script_write();
int generate_random();
void script_write_1();
void script_write_2();
void store(float, int, char []);
typedef struct user_lines
{
    char user_lines[1000];
}lines;
void leaderboard(char []);
void point(lead [], lead* [], int);
void display(lead* [], int);
float find_highest(char []);
float find_fastest(char []);
void view_my_records(char []);