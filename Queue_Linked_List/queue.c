#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"

// Function to initialize a blank queue
void initializeQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->head == NULL);
}

// Function to enqueue a user into the queue
int enqueue(Queue* q, User user) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return 1; // Memory allocation failed
    }

    newNode->data = user;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    return 0;
}

// Function to dequeue a user from the queue
int dequeue(Queue* q, User* user) {

    if (isEmpty(q)) {
        return 1;
    }

    Node* temp = q->head;
    *user = temp->data;

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);

    return 0;
}

// Function to generate a random username
void generateRandomUsername(char* username) {
    char characters[] = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < 10; i++) {
        username[i] = characters[rand() % 36];
    }

    username[10] = '\0';
}

// Function to generate random users and enqueue them
int enqueueRandomUsers(Queue* q, int numberOfUsers) {

    srand(time(NULL));

    for (int i = 0; i < numberOfUsers; i++) {

        User newUser;

        generateRandomUsername(newUser.username);
        newUser.level = (rand() % 60) + 1;
        newUser.faction = rand() % 3;

        if (enqueue(q, newUser) != 0) {
            return 1;
        }
    }

    return 0;
}
