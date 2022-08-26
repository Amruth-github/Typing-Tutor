#include "proj.h"

int check_index(user r_usernames[], char u[], int count)
{
    for(int i = 0;i<count;i++)
    {
        if(!(strcmp(r_usernames[i].username, u)))
        {
            return i;
            break;
        }
    }
}
int check_username(user r_username[], char u[], int count)
{
    int flag = 0;
    for(int i = 0;i<count;i++)
    {
        if (!(strcmp(r_username[i].username, u)))
        {
            flag = 1;
            return flag;
            break;
        }
    }
    if (flag == 0)
    {
        return flag;
    }
}
int  generate_random() 
{
   int l=1, r=3, count=1;
   int rand_num;
   srand(time(0));
   for (int i = 0; i < count; i++) 
   {
      rand_num = (rand() % (r - l + 1)) + l;
   }
   return rand_num;
}