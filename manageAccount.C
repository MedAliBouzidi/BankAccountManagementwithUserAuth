#include "main.h"

void checkBalance(char *username) {
  File *file = fopen("accounts.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  double balance = 0.0;
  char storedUsername[30];
  int found = 0;
  while (fscanf(file, "%s %lf", storedUsername, &balance) != EOF) {
    if (strcmp(storedUsername, username) == 0) {
      found = 1;
      break;
    }
  }
  fclose(file);
  system("clear");
  printf("--- Check Balance ---\n");
}

void deposit(char *username, float amount) {}

void withdraw(char *username, float amount) {}

void updateBalance(char *username, float amount) {}

void viewInfo(char *username) {}
