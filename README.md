# 🏦 Bank Account Management System with User Authentication

## 🎯 Project Goal

A console-based C program that allows users to **register, log in**, and **manage their bank accounts** (check balance, deposit, withdraw, and view account info).

---

## ⚙️ Key Features

### 🔐 Authentication System

- **Register:** Create new accounts with a username and password.
- **Login:** Validate user credentials before accessing the system.
- **Secure Access:** Only authenticated users can perform banking operations.

### 💰 Bank Operations (After Login)

- **Check Balance** – View current balance.
- **Deposit Money** – Add funds to the account.
- **Withdraw Money** – Deduct funds if sufficient balance exists.
- **View Account Info** – Display account details.
- **Logout** – Safely exit the session.

---

## 🧱 System Architecture Overview

```
+--------------------------+
|        Main Menu         |
| 1. Register              |
| 2. Login                 |
| 3. Exit                  |
+-----------+--------------+
            |
            v
+--------------------------+
|   User Authentication    |
| - Check credentials      |
| - Store users in file    |
+-----------+--------------+
            |
            v
+--------------------------+
|   Bank Management Menu   |
| 1. Check Balance         |
| 2. Deposit               |
| 3. Withdraw              |
| 4. View Info             |
| 5. Logout                |
+--------------------------+
```

---

## 🗂️ Files Used

- `users.txt` → Stores username and password.
- `accounts.txt` → Stores username and balance.

### Example Content

```
users.txt
john 12345
mary pass123

accounts.txt
john 1500.50
mary 230.00
```

---

## 🧩 Data Structure Example

```c
typedef struct {
    char username[30];
    char password[30];
    float balance;
} User;
```

---

## 🧠 Functional Modules

| Function            | Purpose                                       |
| ------------------- | --------------------------------------------- |
| `mainMenu()`        | Entry point for register/login/exit           |
| `registerUser()`    | Add a new user and initialize account balance |
| `encryptPassword()` | Simple password encryption                    |
| `decryptPassword()` | Simple password decryption                    |
| `loginUser()`       | Verify credentials and load user data         |
| `bankMenu()`        | Operations after login                        |
| `checkBalance()`    | Display current balance                       |
| `deposit()`         | Add amount and update file                    |
| `withdraw()`        | Subtract amount if sufficient balance         |
| `updateBalance()`   | Write updated balance to file                 |
| `viewInfo()`        | Display logged User data                      |
| `logout()`          | Logout from application                       |

---

## 🧰 Concepts Covered

- File Handling
- Structs
- Strings (for username/password)
- Loops & Conditionals
- Password encryption
- Basic CRUD logic

---
