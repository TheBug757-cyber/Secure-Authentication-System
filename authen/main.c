//main function for the project
#include <stdio.h>
#include "functions.h"

int main()
{
    
    while(1)
    {
      printf("press 1 to register a new user, press 2 to login, 3 to exit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      register_user();
      break;
      case 2:
      login_user();
      break;
      case 3:
      printf("Exiting the program.\n");
      return 0;
      break;
      default:
      printf("Invalid option. Please try again.\n");
     } 
    }

}