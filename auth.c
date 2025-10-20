#include "main.h"

char *encryptPassword(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    password[i] += 10; // Simple Caesar cipher for demonstration
  }
  return password;
}

char *decryptPassword(char *encryptedPassword) {
  for (int i = 0; encryptedPassword[i] != '\0'; i++) {
    encryptedPassword[i] -= 10; // Reverse Caesar cipher
  }
  return encryptedPassword;
}

User *registerUser(char *username, char *password) {
  FILE *file = fopen("accounts.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    return NULL;
  }

  char storedUsername[30];
  while (fscanf(file, "%s", storedUsername) != EOF) {
    if (strcmp(storedUsername, username) == 0) {
      printf("Username already exists!\n");
      fclose(file);
      sleep(2);
      return NULL;
    }
    // Skip the password
    fscanf(file, "%*s");
  }

  char encryptedPassword[30];
  strcpy(encryptedPassword, encryptPassword(password));
  fprintf(file, "%s %s %.2f\n", username, encryptedPassword, 0.0);
  fclose(file);
  printf("Account created successfully!\n");
  User newUser;
  strcpy(newUser.username, username);
  strcpy(newUser.password, password);
  newUser.balance = 0.0;
  sleep(2);
  return &newUser;
}
User loginUser(char *username, char *password) {
  FILE *file = fopen("accounts.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 0;
  }

  User user;
  int found = 0;

  while (fscanf(file, "%s %s %f", user.username, user.password,
                &user.balance) != EOF) {
    if (strcmp(user.username, username) == 0) {
      found = 1;
      break;
    }
  }
  fclose(file);

  if (!found) {
    printf("Username not found!\n");
    sleep(2);
    return 0;
  }

  char decryptedPassword[30];
  strcpy(decryptedPassword, decryptPassword(user.password));
  if (strcmp(decryptedPassword, password) != 0) {
    printf("Incorrect password!\n");
    sleep(2);
    return 0;
  }

  printf("Login successful!\n");
  sleep(2);
  return user;
}

void logout() {
  printf("Logging out...\n");
  sleep(2);
}
