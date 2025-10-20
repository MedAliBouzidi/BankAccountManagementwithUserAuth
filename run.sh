#!/usr/bin/env bash

# Check if accounts.txt exists, if not create it
if [ ! -f "./accounts.txt" ]; then
    touch accounts.txt
fi

# Compile and run the C program
gcc *.c main.h -o program
./program
