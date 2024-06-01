#include <stdio.h>
#include <string.h>

#define MAX_MENU 31
#define MAX_NAME_LEN 26

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
    int exists;
} Menu;

Menu menu[MAX_MENU];
int totalEarnings = 0;

void addMenu(int shelf, char name[], int price) {
    if (menu[shelf].exists) {
        printf("Menu #%d is already exist\n", shelf);
    } else {
        strncpy(menu[shelf].name, name, MAX_NAME_LEN - 1);
        menu[shelf].price = price;
        menu[shelf].exists = 1;
        printf("Added menu #%d %s\n", shelf, name);
    }
}

void infoMenu(int shelf) {
    if (menu[shelf].exists) {
        printf("#%d %s Rp %d\n", shelf, menu[shelf].name, menu[shelf].price);
    } else {
        printf("Menu #%d doesn't exist\n", shelf);
    }
}

void orderMenu(int shelf, int quantity) {
    if (menu[shelf].exists) {
        int totalPrice = menu[shelf].price * quantity;
        totalEarnings += totalPrice;
        printf("Ordered %dx %s for Rp %d\n", quantity, menu[shelf].name, totalPrice);
    } else {
        printf("Menu #%d doesn't exist\n", shelf);
    }
}

void closeCanteen() {
    printf("Earnings: Rp %d\n", totalEarnings);
    printf("TCanteen is closing.. thank you for the visit ^-^\n");
}

int main() {
    char command[10];
    int shelf, price, quantity;
    char name[MAX_NAME_LEN];

    for (int i = 0; i < MAX_MENU; i++) {
        menu[i].exists = 0;
    }

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            scanf("%d", &shelf);
            getchar();
            scanf("%[^\n]", name);
            scanf("%d", &price);
            addMenu(shelf, name, price);
        }
        else if (strcmp(command, "INFO") == 0) {
            scanf("%d", &shelf);
            infoMenu(shelf);
        }
        else if (strcmp(command, "ORDER") == 0) {
            scanf("%d %d", &shelf, &quantity);
            orderMenu(shelf, quantity);
        }
        else if (strcmp(command, "CLOSE") == 0) {
            closeCanteen();
            break;
        }
        else {
            printf("Unknown command!\n");
        }
    }
}
