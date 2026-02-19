#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    int numberOfUsers = atoi(argv[1]);

    Queue q;
    initializeQueue(&q);

    if (enqueueRandomUsers(&q, numberOfUsers) != 0) {
        printf("Error adding users to queue.\n");
        return 1;
    }

    printf("Dequeuing Users:\n");

    User tempUser;

    while (!isEmpty(&q)) {

        if (dequeue(&q, &tempUser) == 0) {

            printf("Username: %s\n", tempUser.username);
            printf("Level: %d\n", tempUser.level);

            if (tempUser.faction == RED)
                printf("Faction: Red\n");
            else if (tempUser.faction == BLUE)
                printf("Faction: Blue\n");
            else
                printf("Faction: Green\n");

            printf("--------------------------\n");
        }
    }

    return 0;
}
