#include <stdio.h>
#include <string.h>
struct Item {
    char name[50];
    int quantity;
};

void addItem(struct Item inventory[], int *size) {
    printf("Enter item name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

void updateItem(struct Item inventory[], int size) {
    char itemName[50];
    int newQuantity,i;
    printf("Enter item name: ");
    scanf("%s", itemName);
    for (i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem(struct Item inventory[], int *size) {
    char itemName[50];
    int i,j;
    printf("Enter item name: ");
    scanf("%s", itemName);
    for (i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void checkStock(struct Item inventory[], int size) {
    char itemName[50];
    int i;
    printf("Enter item name: ");
    scanf("%s", itemName);
    for (i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
	int a = 71194;
	int b ;
	printf("enter pasword");
	scanf("%d",&b);
	if (a==b){
        struct Item inventory[100];
        int size = 0;
        int choice;
        while (1) {
            printf("Inventory Management System\n");
            printf("2. Update item\n");
            printf("3. Delete item\n");
            printf("4. Check stock level\n");
            printf("1. Add item\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    addItem(inventory, &size);
                    break;
                case 2:
                    updateItem(inventory, size);
                    break;
                case 3:
                    deleteItem(inventory, &size);
                    break;
                case 4:
                    checkStock(inventory, size);
                    break;
                case 5:
                    printf("you have exited \nThankyou??");
                    return 0;
                default:
                    printf("Invalid choice! Please try again.\n");
        }
    }
    }else{
    	printf("wrong pasword");
	}
    return 0;
}
