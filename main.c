//main function for the project
#include <stdio.h>
#include "functions.h"

int main()
{
    printf("press 1 to register a new user or press 2 to login\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        register_user();
    }
    else if (choice == 2)
    {
        login_user();
    }
    else
    {
        printf("Invalid option. Please try again.\n");
    }


    return 0;

}