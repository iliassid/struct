#include <stdio.h>
#include <string.h>

typedef struct {
    char street[100];
    char city[100];
    int zipCode;
}Adress;
typedef struct {
    char name[100];
    int age;
    Adress adress;
}Persons;

Persons person[100];
int nbr_person = 0;


int add_person() {
    if (nbr_person<100)
    {
        printf("Enter the person name:");
    scanf("%s", person[nbr_person].name);
    prinf("Enter the person age:");
    scanf("%d", &person[nbr_person].age);
    printf("Enter the person adress : ");
    printf("Enter the person street :");
    scanf("%s", person[nbr_person].adress.street);
    printf("Enter the person city :");
    scanf("%s", person[nbr_person].adress.city);
    printf("Enter the person zipcode");
    scanf("%d", &person[nbr_person].adress.zipcode);
    nbr_person++;
    return 1;
    }
    else
    {
        printf("The max number of people is reached");
        return 0;
    }   
}
int showPerson () {
    if (nbr_person==0)
    {
        printf("There is no person in the list.");
    }else
    {
        printf("the persons in the list :");
        for (int i = 0; i < nbr_person; i++)
        {
            printf("person %d :", i+1);
            printf("name :%s", person[i].name);
            printf("age :%d", &person[i].age);
            printf("adress:\n street:%s\n city:%s\n zipcode:%d",person[i].adress.street, person[i].adress.city, person[i].adress.zipCode );
        }
        
    }
}
int editperson(){
    printf("");
}