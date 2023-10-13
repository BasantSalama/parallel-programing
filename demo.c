#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define UserName_LENGTH 12
#define Password_LENGTH 10

typedef struct {
    char username[UserName_LENGTH];
    char password[Password_LENGTH];
} User;

User users[];
int numUsers = 0;

void registeration() {
   

    User newUser;
    printf("Enter your username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf(" This Username already exists. Please Enter a different username.\n");
            return;
        }
    }

    printf("Enter your password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void login() {
    char username[UserName_LENGTH];
    char password[Password_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf(" Invalid username or password. \n");
}

int main() {
    int choice;

    while (1) {
        printf("1 Register\n");
        printf("2 Login\n");
        printf("3 Exit\n");
        printf("chose 1 , 2 or 3 :- ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registeration();
                break;
            case 2 :
                login();
                break;
            case 3 :
                printf("Exit\n");
                exit(0);
            default:
                printf(" This choice not avaliable.\n");
        }

        printf("\n");
    }
}