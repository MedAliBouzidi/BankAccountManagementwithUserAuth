#!/usr/bin/env bash

# Check if users.txt exists, if not create it
if [! -f "./users.txt" ]; then
    touch users.txt
fi

# Check if accounts.txt exists, if not create it
if [! -f "./accounts.txt" ]; then
    touch accounts.txt
fi

# Compile and run the C program
gcc *.c main.h -o program
./program
