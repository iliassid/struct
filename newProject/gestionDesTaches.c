#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100 

typedef struct {
    char titre[100];
    char description[200];
    char date_echeance[20];  
    char priorite[10];  
} task;


task tasks[MAX_TASKS];
int nb_tasks = 0; 



void showMenu() {
    printf("Task Management Menu:\n");
    printf("1. Add a task\n");
    printf("2. Show all tasks\n");
    printf("3. Edit a task\n");
    printf("4. Delete a task\n");
    printf("5. Filter tasks by priority\n");
    printf("6. Quit\n"); 
    printf("Enter your choice: ");
    
}


void addTask() {
    if (nb_tasks < MAX_TASKS) {
        printf("Enter the title of the task: ");
        
        scanf(" %[^\n]", tasks[nb_tasks].titre);

        printf("Enter the description of the task: ");
        
        scanf(" %[^\n]", tasks[nb_tasks].description);

        printf("Enter the due date (dd/MM/yyyy): ");
        scanf(" %[^\n]", tasks[nb_tasks].date_echeance);

        do {
            printf("Enter priority (High/Low): ");
            scanf(" %s", tasks[nb_tasks].priorite);
        } while (strcmp(tasks[nb_tasks].priorite, "High") != 0 && strcmp(tasks[nb_tasks].priorite, "Low") != 0);

        nb_tasks++;
        printf("Task added successfully!\n");
    } else {
        printf("The maximum number of tasks has been reached.\n");
    }
}


void showTasks() {
    if (nb_tasks == 0) {
        printf("No tasks to display.\n");
    } else {
        printf("List of tasks:\n");
        for (int i = 0; i < nb_tasks; i++) {
            printf("\nTask %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].titre);
            printf("Description: %s\n", tasks[i].description);
            printf("Due date: %s\n", tasks[i].date_echeance);
            printf("Priority: %s\n", tasks[i].priorite);
        }
    }
}


void editTask() {
    int index;
    printf("Enter the index of the task to modify (1-%d): ", nb_tasks);
    scanf("%d", &index);

    if (index > 0 && index <= nb_tasks) {
        index--;  
        printf("Changes the task %d:\n", index + 1);

        printf("Enter the new title: ");
        scanf(" %[^\n]", tasks[index].titre);

        printf("Enter the new description: ");
        scanf(" %[^\n]", tasks[index].description);

        printf("Enter the new due date (JJ/MM/AAAA): ");
        scanf(" %[^\n]", tasks[index].date_echeance);

        do {
            printf("Enter the new priority (High/Low): ");
            scanf(" %9s", tasks[nb_tasks].priorite);
        } while (strcmp(tasks[nb_tasks].priorite, "High") != 0 && strcmp(tasks[nb_tasks].priorite, "Low") != 0 );

        printf("Task successfully modified!\n");
    } else {
        printf("Task not found!\n");
    }
}


void deleteTask() {
    int index;
    printf("Enter the index of the task to be deleted (1-%d): ", nb_tasks);
    scanf("%d", &index);

    if (index > 0 && index <= nb_tasks) {
        index--;  
        for (int i = index; i < nb_tasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        nb_tasks--;
        printf("Task successfully removed!\n");
    } else {
        printf("Task not found!\n");
    }
}


void filterByPriority() {
    char prior[10];
    printf("Enter the priority to filter (High/Low): ");
    scanf("%9s", prior);

    printf("Priority task list %s:\n", prior);
    int trouve = 0;
    for (int i = 0; i < nb_tasks; i++) {
        if (strcmp(tasks[i].priorite, prior) == 0) {
            printf("\nTask %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].titre);
            printf("Description: %s\n", tasks[i].description);
            printf("Due date: %s\n", tasks[i].date_echeance);
            printf("Priority: %s\n", tasks[i].priorite);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("No task found with this priority.\n");
    }
}

int main() {
    int choix;

    do {
        
        showMenu();
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                addTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                filterByPriority();
                break;
            case 6:
                printf("Thank you for using the task management application!\n");
                break;
            default:
                printf("Invalid choice. Please try again..\n");
        }
    } while (choix != 6);

    return 0;
}

    