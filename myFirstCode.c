#include <stdio.h>
#include <string.h>

typedef struct
{
    char street[100];
    char city[100];
    int zip_code;
} adress;

typedef struct {
    int age;
    char name[100];
    adress adr;
} person;

int main() {
    person pers[100];
    int nbr_person = 0;
    int choice;
    
    do {
        printf("\nMenu :");
        printf("\n1. Add a person");
        printf("\n2. Show all the persons");
        printf("\n3. Edit a person info");
        printf("\n4. Delete a person");
        printf("\n5. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (nbr_person < 100) {
                    printf("Enter the person's age: ");
                    scanf("%d", &pers[nbr_person].age);
                    printf("Enter the person's name: ");
                    scanf("%s", pers[nbr_person].name);
                    printf("Enter the person's street: ");
                    scanf("%s", pers[nbr_person].adr.street);
                    printf("Enter the person's city: ");
                    scanf("%s", pers[nbr_person].adr.city);
                    printf("Enter the person's zip code: ");
                    scanf("%d", &pers[nbr_person].adr.zip_code);
                    nbr_person++;
                } else {
                    printf("The maximum number of people has been reached.\n");
                }
                break;

            case 2:
                if (nbr_person == 0) {
                    printf("There are no persons in the list.\n");
                } else {
                    printf("The persons in the list are:\n");
                    for (int i = 0; i < nbr_person; i++) {
                        printf("Name: %s\n", pers[i].name);
                        printf("Age: %d\n", pers[i].age);
                        printf("Street: %s, City: %s, Zip Code: %d\n",
                               pers[i].adr.street, pers[i].adr.city, pers[i].adr.zip_code);
                    }
                }
                break;

            case 3: {
                int index;
                printf("Enter the number of the person in the list (0-%d): ", nbr_person - 1);
                scanf("%d", &index);

                if (index >= 0 && index < nbr_person) {
                    printf("Update the person's info:\n");
                    printf("Enter the new name: ");
                    scanf("%s", pers[index].name);
                    printf("Enter the new age: ");
                    scanf("%d", &pers[index].age);
                    printf("Enter the new street: ");
                    scanf("%s", pers[index].adr.street);
                    printf("Enter the new city: ");
                    scanf("%s", pers[index].adr.city);
                    printf("Enter the new zip code: ");
                    scanf("%d", &pers[index].adr.zip_code);
                } else {
                    printf("Index unavailable.\n");
                }
                break;
            }

            case 4: {
                int index;
                printf("Enter the person index to delete (0-%d): ", nbr_person - 1);
                scanf("%d", &index);

                if (index >= 0 && index < nbr_person) {
                    // Shift the remaining people to delete the person
                    for (int i = index; i < nbr_person - 1; i++) {
                        pers[i] = pers[i + 1];
                    }
                    nbr_person--; // Reduce the number of persons
                    printf("Person deleted.\n");
                } else {
                    printf("Index unavailable.\n");
                }
                break;
            }

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}



