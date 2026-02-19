#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "user.h"

// Structure to represent a node in the queue
// Each node contains a User and a pointer to the next node
typedef struct node {
    User data;
    struct node* next;
} Node;

// Structure to represent the queue
// Contains pointers to the head and tail of the queue
typedef struct {
    Node* head;
    Node* tail;
} Queue;

// Function Prototypes

// Initializes a blank queue
void initializeQueue(Queue* q);

// Checks if the queue is empty
int isEmpty(Queue* q);

// Adds a user to the queue
int enqueue(Queue* q, User user);

// Removes a user from the queue
int dequeue(Queue* q, User* user);

// Adds randomly generated users to the queue
int enqueueRandomUsers(Queue* q, int numberOfUsers);

#endif
