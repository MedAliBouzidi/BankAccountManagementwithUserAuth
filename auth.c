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

char registerUser(User *user) {
    FILE *file = fopen("accounts.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    char storedUsername[30];
    while (fscanf(file, "%s", storedUsername) != EOF) {
        if (strcmp(storedUsername, user->username) == 0) {
            printf("Username already exists!\n");
            fclose(file);
            sleep(2);
            return 0;
        }
        // Skip the password
        fscanf(file, "%*s %*f");
    }

    strcpy(user->password, encryptPassword(user->password));
    fprintf(file, "%s %s %.2f\n", user->username, user->password, 0.0);
    fclose(file);
    printf("Account created successfully!\n");
    sleep(2);
    return 1;
}

char loginUser(User user) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    User foundUser;
    int found = 0;

    while (fscanf(file, "%s %s %f", foundUser.username, foundUser.password, &foundUser.balance) != EOF) {
        if (strcmp(user.username, foundUser.username) == 0) {
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

    if (strcmp(decryptPassword(foundUser.password), user.password) != 0) {
        printf("Incorrect password!\n");
        sleep(2);
        return 0;
    }

    printf("Login successful!\n");
    sleep(2);
    return 1;
}

void logout() {
    printf("Logging out...\n");
    sleep(2);
}
