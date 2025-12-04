#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char username[50];
    char password[100];
};

struct user  *user_list = NULL;
static int user_count = 0;

int validate_password(const char* password) 
{
    //returns 1 if password is valid, else returns 0
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    const char special_characters[] = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
    for (int i = 0; i < length; i++) 
    {
        if (password[i] >= 'A' && password[i] <= 'Z') 
        {
            has_upper = 1;
        } 
        else if (password[i] >= 'a' && password[i] <= 'z') 
        {
            has_lower = 1;
        } 
        else if (password[i] >= '0' && password[i] <= '9') 
        {
            has_digit = 1;
        } 
        else if (strchr(special_characters, password[i])) 
        {
            has_special = 1;
        }
    }
    if (length < 8 || !has_upper || !has_lower || !has_digit || !has_special) 
    {
       return 0;
    }
    return 1;
}

void register_user() 
{
    // Implementation for user registration
    struct user new_user;

    
    user_list = realloc(user_list, (user_count + 1) * sizeof(struct user));
    if (user_list == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    user_list[user_count] = new_user;
    user_count++;


    printf("-----------Register----------------\n");
    printf("Enter a username: \n");
    scanf("%s", new_user.username);

    while(1)
    //loop continues until user enters a valid password and displays appropriate message
    {

        printf("Enter a password: \n");
        scanf("%s", new_user.password);
        if(validate_password(new_user.password)) 
        {
            strcpy(user_list[user_count - 1].username, new_user.username);
            strcpy(user_list[user_count - 1].password, new_user.password);
            printf("User %s registered successfully!\n", new_user.username);
            break;
        }
        else
        {
            printf("Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        
        }
        encrypt_password(new_user.password, user_list[user_count - 1].password);
    }
}

void login_user() 
{
    // Implementation for user login
    struct user login_user;
    int allowed_attempts = 3;
    while(allowed_attempts > 0) 
    {
    printf("-----------Login----------------\n");
    printf("Enter your username: \n");
    scanf("%s", login_user.username);
    printf("Enter your password: \n");
    scanf("%s", login_user.password);
    
    encrypt_password(login_user.password, login_user.password);
    
        for(int i = 0; i < user_count; i++) 
        {
            if(strcmp(user_list[i].username, login_user.username) == 0 && strcmp(user_list[i].password, login_user.password) == 0) 
            {
                printf("Login successful! Welcome %s\n", login_user.username);
                break;
            }
            else{
                allowed_attempts--;
                if(allowed_attempts == 0) 
                {
                    printf("Login failed! No attempts left. Exiting login.\n");
                    return;
                } 
                else 
                {
                    printf("Login failed! You have %d attempts left. Please try again.\n", allowed_attempts);
                    break;
                }
            }
        
       
    }
}
}

void encrypt_password(const char* password, char* encrypted) 
{
    //encrypts the password using a simple Caesar cipher with a shift of 3 
    int length = strlen(password);
    for (int i = 0; i < length; i++) 
    {
        encrypted[i] = password[i] + 3;
    }   
    encrypted[length] = '\0';   

}

    

