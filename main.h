#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// User structure
typedef struct {
  char username[30];
  char password[30];
  float balance;
} User;

// Entry point for register/login/exit
void mainMenu();
// Password encryption
char *encryptPassword(char *password);
// Password decryption
char *decryptPassword(char *encryptedPassword);
// Add a new user and initialize account balance
User *registerUser(char *username, char *password);
// Verify credentials and load user data
User loginUser(char *username, char *password);
// Operations after login
void bankMenu(User user);
// Display current balance
void checkBalance(User user);
// Add amount and update file
void deposit(User user, float amount);
// Subtract amount if sufficient balance
void withdraw(User user, float amount);
// Write updated balance to file
void updateBalance(User user, float amount);
// Display logged User data
void viewInfo(User user);
// Logout from application
void logout();

#endif
