/**
 * @file system.h
 * @author Poosa Anusha (poosa.anusha@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _SYSTEM_H
#define _SYSTEM_H
#include <stdio.h>

char name[5][50] = {
    "Muta Gopal-TRS",
    "Dr.K.Laxman-BJP",
    "T.Manemma-Congress",
    "S.Rajeswar-Independent",
    "Others",
};

struct Voting
{
  int Vote;
};
struct Voting temp[5];
void Listcandidates(void);
void startup()
{
  printf("====Welcome to 2021 Elections=====\n");
  int choice;
  printf("%s\n", "1. Cast The Vote");
  printf("%s\n", "2. Find Vote Count");
  printf("%s\n", "3. Find Leading Candidate");
  printf("%s\n", "4. Exit");
  printf("=================================\n");
  printf("%s", "Please Enter Your Choice : ");
  scanf("%d", &choice);
  int i;
  switch (choice)
  {
  case 1:
    Listcandidates();
    break;
  case 2:
    printf("=================================\n");

    for (i = 0; i < 5; i++)
    {
      printf("%d:\t%s\t%d\n", (i + 1), name[i], temp[i].Vote);
    }
    printf("=================================\n");
    startup();
    break;
  case 3:
    printf("Leading\n=================================\n");

    int location = 0;
    for (i = 0; i < 5; i++)
    {
      for (i = 1; i < 5; i++)
      {
        if (temp[i].Vote > temp[location].Vote)
        {
          location = i;
        }
      }
    }

    printf("Leading Candidate by '%s' with No.of Votes : %d\n", name[location], temp[location]);

    printf("=================================\n");
    startup();
    break;
  case 4:
    printf("Exited !");
    break;
  default:

    printf("Invalid Choice");
  };
}

void Listcandidates(void)
{
  printf("=================================\n");
  printf("\n%s\n", "Please Choose Your Candidate");
  int i;
  for (i = 0; i < 5; i++)
  {
    //printf("%d:\t%s\t%d\n", (i + 1), name[i], temp[i].Vote);
    printf("%d:\t%s\n", (i + 1), name[i]);
  }
  printf("=================================\n");
  printf("\n%s", "Input Your Choice (1 - 5) : ");
  int choice;
  scanf("%d", &choice);
  temp[choice - 1].Vote = temp[choice - 1].Vote + 1;
  startup();
};
#endif





