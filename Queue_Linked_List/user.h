#pragma once
#ifndef USER_H
#define USER_H

// Enumeration to represent the faction of a user
// Using enum improves readability and prevents invalid faction values
typedef enum {
    RED,
    BLUE,
    GREEN
} Faction;

// Structure to represent a user in the game
typedef struct {
    char username[11];   // 10 characters + null terminator
    int level;           // Level ranges from 1 to 60
    Faction faction;     // RED, BLUE, or GREEN
} User;

#endif
