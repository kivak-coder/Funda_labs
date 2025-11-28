#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"

int main() {
    LinkedList* list = NULL;
    int choice;
    size_t index;
    
    do {
        printf("\n=== Linked List Manager ===\n");
        printf("1. Create list\n");
        printf("2. Add element to front\n");
        printf("3. Add element to back\n");
        printf("4. Insert element at index\n");
        printf("5. Remove element from front\n");
        printf("6. Remove element from back\n");
        printf("7. Delete element at index\n");
        printf("8. Get element at index\n");
        printf("9. Clear list\n");
        printf("10. Delete list\n");
        printf("11. Check lists equality\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(list != NULL) {
                    printf("List already exists. Delete it first.\n");
                } else {
                    list = createList();
                    if(list) printf("List created successfully\n");
                    else printf("Failed to create list\n");
                }
                break;
                
            case 2:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    // Здесь должен быть код создания Liver и pushFrontList
                    printf("Function not fully implemented\n");
                }
                break;
                
            case 3:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    // Здесь должен быть код создания Liver и pushBackList
                    printf("Function not fully implemented\n");
                }
                break;
                
            case 4:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    printf("Enter index: ");
                    scanf("%zu", &index);
                    // Здесь должен быть код создания Liver и InsertAtList
                    printf("Function not fully implemented\n");
                }
                break;
                
            case 5:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    Liver* liver = popFrontList(list);
                    if(liver) {
                        printf("Element removed from front\n");
                        // Дополнительная обработка liver
                    } else {
                        printf("List is empty\n");
                    }
                }
                break;
                
            case 6:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    Liver* liver = popBackList(list);
                    if(liver) {
                        printf("Element removed from back\n");
                        // Дополнительная обработка liver
                    } else {
                        printf("List is empty\n");
                    }
                }
                break;
                
            case 7:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    printf("Enter index to delete: ");
                    scanf("%zu", &index);
                    DeleteAtList(list, index);
                    printf("Element deleted\n");
                }
                break;
                
            case 8:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    printf("Enter index: ");
                    scanf("%zu", &index);
                    Liver* liver = getAtList(list, index);
                    if(liver) {
                        printf("Element retrieved\n");
                        // Вывод информации о liver
                    } else {
                        printf("Invalid index\n");
                    }
                }
                break;
                
            case 9:
                if(!list) {
                    printf("Create list first\n");
                } else {
                    eraseList(list);
                    printf("List cleared\n");
                }
                break;
                
            case 10:
                if(list) {
                    deleteList(list);
                    list = NULL;
                    printf("List deleted\n");
                } else {
                    printf("No list to delete\n");
                }
                break;
                
            case 11:
                printf("Function not implemented\n");
                break;
                
            case 0:
                if(list) {
                    deleteList(list);
                }
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);
    
    return 0;
}