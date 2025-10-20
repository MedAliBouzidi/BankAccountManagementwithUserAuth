#include "main.h"
#include <stdio.h>

int main() {
  mainMenu();
  return 0;
}

void bankMenu(User user) {
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
      checkBalance(user);
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
    }
  }
}

void mainMenu() {
  short option = 0;

  while (option != 3) {
    system("clear");

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
      User user;

      while (user == NULL) {
        system("clear");
        printf("---- Create Account ----\n");
        printf("Enter Username: ");
        scanf("%s", user.username);
        printf("Enter Password: ");
        scanf("%s", user.password);
        printf("------------------------\n");
        registerUser(user.username, user.password)
      }
      break;
    }
    case 2: {
      char success = 0;
      char username[30];
      char password[30];

      while (success != 1) {
        system("clear");
        printf("---- Access Account ----\n");
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter Password: ");
        scanf("%s", password);
        printf("------------------------\n");
        success = loginUser(username, password);
      }
      bankMenu(username);
      break;
    }
    case 3:
      printf("Exiting...\n");
      break;
    }
  }
}
