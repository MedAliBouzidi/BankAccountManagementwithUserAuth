#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char username[30];
  char password[30];
  float balance;
} User;

void mainMenu();
char *encryptPassword(char *password);
char *decryptPassword(char *encryptedPassword);
char registerUser(User *user);
char loginUser(User user);
void logout();
void bankMenu(User *user);
void checkBalance(User user);
void deposit(User *user, float amount);
void withdraw(User *user, float amount);
void viewInfo(User user);

#endif
