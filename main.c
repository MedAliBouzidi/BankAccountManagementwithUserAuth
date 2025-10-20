#include "main.h"

int main() {
    mainMenu();
    return 0;
}

void bankMenu(User *user) {
    short option = 0;

    while (option != 5) {
        system("clear");

        printf("--- Bank Account Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Info\n");
        printf("5. Logout\n");
        printf("-------------------------\n");
        printf("Select an option: ");
        scanf("%hd", &option);
        switch (option) {
            case 1:
                checkBalance(*user);
                break;
            case 2:
                // deposit(username, amount);
                break;
            case 3:
                // withdraw(username, amount);
                break;
            case 4:
                // viewInfo(username);
                break;
            case 5:
                printf("Logging out...\n");
                sleep(2);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

void mainMenu() {
    short option = 0;

    while (option != 3) {
        system("clear");

        User user = {.username = "", .password = "", .balance = 0.0};

        printf("--- Bank Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Access Account\n");
        printf("3. Exit\n");
        printf("-----------------\n");
        printf("Select an option: ");
        scanf("%hd", &option);
        switch (option) {
            case 1: {
                char success = 0;
                while (success == 0) {
                    system("clear");
                    printf("---- Create Account ----\n");
                    printf("Enter Username: ");
                    scanf("%s", user.username);
                    printf("Enter Password: ");
                    scanf("%s", user.password);
                    printf("------------------------\n");
                    success = registerUser(&user);
                }
                bankMenu(&user);
                break;
            }
            case 2: {
                char success = 0;
                while (success == 0) {
                    system("clear");
                    printf("---- Access Account ----\n");
                    printf("Enter Username: ");
                    scanf("%s", user.username);
                    printf("Enter Password: ");
                    scanf("%s", user.password);
                    printf("------------------------\n");
                    success = loginUser(user);
                }
                bankMenu(&user);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}
