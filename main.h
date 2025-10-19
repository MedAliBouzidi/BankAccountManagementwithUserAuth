#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

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
void registerUser(char *username, char *password);
// Verify credentials and load user data
void loginUser(char *username, char *password);
// Operations after login
void bankMenu();
// Display current balance
void checkBalance(char *username);
// Add amount and update file
void deposit(char *username, float amount);
// Subtract amount if sufficient balance
void withdraw(char *username, float amount);
// Write updated balance to file
void updateBalance(char *username, float amount);
// Display logged User data
void viewInfo(char *username);
// Logout from application
void logout();

#endif
